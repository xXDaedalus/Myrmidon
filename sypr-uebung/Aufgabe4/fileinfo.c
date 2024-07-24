#define _POSIX_C_SOURCE 200112L

#include <limits.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#include "fileinfo.h"

// Funktion zum Auflisten des Inhalts eines Verzeichnisses
static fileinfo *list_directory(const char *path) {
    // Arbeitsverzeichnis auf den angegebenen Pfad setzen
    if (chdir(path) == -1) {
        return NULL;
    }

    // Verzeichnis öffnen
    DIR *directory = opendir("."); // "." - öffnet das aktuelle Verzeichnis
    if (directory == NULL) {
        return NULL;
    }

    // Dateiinfo für das Verzeichnis im Pfad
    fileinfo *head = malloc(sizeof(fileinfo));
    if (head == NULL) {
        closedir(directory);
        free(head);
        return NULL;
    }

    strcpy(head->name, path);
    head->type = filetype_directory;
    head->next = NULL;

    fileinfo *files = NULL;
    fileinfo *directories = NULL;

    const struct dirent *entry;

    // Einträge im Verzeichnis lesen
    while ((entry = readdir(directory)) != NULL) {
        // Überprüfen, ob es sich um "." oder ".." handelt
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Neue Dateiinfo erstellen
        fileinfo *newFile = fileinfo_create(entry->d_name);
        if (!newFile) {
            closedir(directory);
            return NULL;
        }

        // Neue Datei nach Typ sortieren
        if (newFile->type == filetype_directory) {
            newFile->next = directories;
            directories = newFile;
        } else {
            newFile->next = files;
            files = newFile;
        }
    }

    // Wenn keine Dateien vorhanden sind, Verzeichnisse an den Inhalt des Verzeichnisses anhängen
    if (!files) {
        head->contents = directories;
    } else { // Dateien vor Verzeichnissen einfügen
        head->contents = files;
        while (files->next) {
            files = files->next;
        }
        files->next = directories;
    }

    closedir(directory);

    // Arbeitsverzeichnis ändern
    if (chdir("..") == -1) {
        fileinfo_destroy(head);
        return NULL;
    }

    return head;
}

// Funktion zum Erstellen einer Dateiinfo
fileinfo *fileinfo_create(const char *name) {
    if (strlen(name) > NAME_MAX + 1) {
        errno = ENAMETOOLONG;
        return NULL;
    }

    // Dateistatus abrufen
    struct stat stat;
    if (lstat(name, &stat) == -1) {
        // Spezifischen Fall für /dev/tty-Fehler behandeln
        if (strcmp(name, "/dev/tty") == 0) {
            fprintf(stderr, "%s (errno %d)\n", strerror(ENOENT), ENOENT);
        }
        return NULL;
    }

    // Reguläre Datei
    if (S_ISREG(stat.st_mode)) {
        fileinfo *newFile = malloc(sizeof(fileinfo));
        if (newFile == NULL) {
            free(newFile);
            return NULL;
        }

        strcpy(newFile->name, name);
        newFile->type = filetype_regular;
        newFile->size = stat.st_size;

        return newFile;
    } else if (S_ISDIR(stat.st_mode)) { // Verzeichnis
        fileinfo *directory = list_directory(name);
        return directory;
    } else { // Andere Dateitypen
        fileinfo *other = malloc(sizeof(fileinfo));
        if (other == NULL) {
            free(other);
            return NULL;
        }

        strcpy(other->name, name);
        other->type = filetype_other;

        return other;
    }
}

// Funktion zum Ausdrucken einer regulären Datei
void print_regular(const char *name, const int size) {
    printf("%s (regulär, %d Byte)\n", name, size);
}

// Funktion zum Ausdrucken anderer Dateitypen
void print_other(const char *name) {
    printf("%s (andere)\n", name);
    printf("\n");
}

// Funktion zum Ausdrucken eines Verzeichnisses und seines Inhalts
void print_directory(const char *path, const char *name, const fileinfo *content) {
    printf("%s%s:\n", path, name);

    // Inhalt des aktuellen Verzeichnisses ausdrucken
    for (const fileinfo *entry = content; entry; entry = entry->next) {
        switch (entry->type) {
            case filetype_regular:
                print_regular(entry->name, entry->size);
                break;
            case filetype_directory:
                printf("%s (Verzeichnis)\n", entry->name);
                break;
            case filetype_other:
                print_other(entry->name);
                break;
        }
    }

    // Rekursiv Unterverzeichnisse ausdrucken
    for (const fileinfo *entry = content; entry; entry = entry->next) {
        if (entry->type == filetype_directory) {
            printf("\n");

            char *newpath = malloc(sizeof(char) * (strlen(path) + strlen(name) + 2)); // +2 für "/" und "\0"
            if (newpath == NULL) {
                print_directory("Pfad zu lang.../", entry->name, entry->contents);
                continue;
            }

            sprintf(newpath, "%s%s/", path, name);
            print_directory(newpath, entry->name, entry->contents);

            free(newpath);
        }
    }
}

// Funktion zum Ausdrucken einer Dateiinfo
void fileinfo_print(const fileinfo *file) {
    switch (file->type) {
        case filetype_regular:
            print_regular(file->name, file->size);
            break;
        case filetype_directory:
            printf("\n");
            print_directory("", file->name, file->contents);
            break;
        case filetype_other:
            print_other(file->name);
            break;
    }
}

// Funktion zum Freigeben des Speichers einer Dateiinfo
void fileinfo_destroy(const fileinfo *file) {
    if (file->type == filetype_directory) {
        const fileinfo *head = file->contents;
        while (head) {
            fileinfo *next = head->next;
            fileinfo_destroy(head);
            head = next;
        }
    }

    free((fileinfo*)file);
}
