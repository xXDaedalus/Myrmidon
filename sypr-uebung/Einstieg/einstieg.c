/*
 * einstieg.c
 *
 * Das erste C-Programm gibt einen Text aus.
 * 
 * Autor: Kevin Haas
 * Erstellt am: 01.04.2024
 */

#include <stdio.h>

int main(void)
{
    printf("Anzahl bisher geschriebener C-Programme eingeben: ");
    int anzahl;
    scanf("%d", &anzahl);

    printf("Vorname eingeben: ");
    char *vorname = (char*) malloc(8);
    scanf("%s", vorname);

    printf("%ss %d. C-Programm funktioniert!\n", vorname, anzahl + 1);

    return 0;
}