#ifndef AUFGABE4_FILEINFO_H
#define AUFGABE4_FILEINFO_H

#include <limits.h>
#include <stddef.h>

enum filetype{
    filetype_regular,
    filetype_directory,
    filetype_other
};

struct fileinfo {
    char name[NAME_MAX + 1];

    enum filetype type;

    struct fileinfo *next;

    union {
        size_t size;
        struct fileinfo *contents;
    };
};

typedef struct fileinfo fileinfo;

fileinfo *fileinfo_create(const char *name);
void fileinfo_print(const fileinfo *f);
void fileinfo_destroy(const fileinfo *f);

#endif //AUFGABE4_FILEINFO_H
