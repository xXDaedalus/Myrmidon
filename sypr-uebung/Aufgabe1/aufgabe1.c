#include <stdio.h>

int main()
{
    // Definition und Initialisierung der Variablen
    int i = 42;
    long l = 1234567890;
    char c = 'A';
    float f = 3.14;
    double d = 2.71828;
    short sh = 32767;
    long long ll = 9223372036854775807LL;
    signed int si = -2147483648;
    signed long sl = -2147483648L;
    signed char sc = -128;
    signed short ss = -32768;
    unsigned char uc = 255;
    unsigned short us = 65535;
    unsigned int ui = 65535;
    unsigned long ul = 4294967295;
    unsigned long long ull = 18446744073709551615ULL;
    // Zeigerdefinition
    const char* s = "Hallo";

    // Ausgabe der Variableninformationen
    printf("Adresse\t\t| Platzbedarf\t| Typ\t\t\t| Name\t\t| Wert\n");
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %d\n",
    (void*)&i, (int)sizeof(int), "int", "i", i);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %ld\n",
    (void*)&l, (int)sizeof(long), "long", "l", l);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %c\n",
    (void*)&c, (int)sizeof(char), "char", "c", c);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %.2f\n",
    (void*)&f, (int)sizeof(float), "float", "f", f);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %.5lf\n",
    (void*)&d, (int)sizeof(double), "double", "d", d);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %hd\n",
    (void*)&sh, (int)sizeof(short), "short", "sh", sh);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %lld\n",
    (void*)&ll, (int)sizeof(long long), "long long", "ll", ll);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %d\n",
    (void*)&si, (int)sizeof(signed int), "signed int", "si", si);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %ld\n",
    (void*)&sl, (int)sizeof(signed long), "signed long", "sl", sl);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %hhd\n",
    (void*)&sc, (int)sizeof(signed char), "signed char", "sc", sc);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %hd\n",
    (void*)&ss, (int)sizeof(signed short), "signed short", "ss", ss);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %hhu\n",
    (void*)&uc, (int)sizeof(unsigned char), "unsigned char", "uc", uc);
    
    printf("%p\t| %d\t\t| %s\t| %s\t\t| %hu\n",
    (void*)&us, (int)sizeof(unsigned short), "unsigned short", "us", us);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %u\n",
    (void*)&ui, (int)sizeof(unsigned int), "unsigned int", "ui", ui);

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %lu\n",
    (void*)&ul, (int)sizeof(unsigned long), "unsigned long", "ul", ul);
    
    printf("%p\t| %d\t\t| %s\t| %s\t\t| %llu\n",
    (void*)&ull, (int)sizeof(unsigned long long), "unsigned long long", "ull", ull);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %s\n",
    (void*)&s, (int)sizeof(s), "char*", "s", s);

    // Ausgabe des C-Datenmodells
#if defined(__ILP32__)
    printf("\n Das Programm arbeitet mit dem C-Datenmodell ILP32.\n");
#elif defined(__LP64__)
    printf("\n Das Programm arbeitet mit dem C-Datenmodell LP64.\n");
#elif defined(__LLP64__)
    printf("\n Das Programm arbeitet mit dem C-Datenmodell LLP64.\n");
#else
    printf("\n Das Programm arbeitet mit keinem der drei genannten C-Datenmodelle.\n");
#endif

    return 0;
}
