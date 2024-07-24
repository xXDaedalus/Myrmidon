#include <stdio.h>

int main()
{
    /* Definition und Initialisierung der Variablen */
    int i = 42;
    long l = 1234567890;
    char c = 'A';
    float f = 3.14;
    double d = 2.71828;
    short sh = 32767;
    unsigned int ui = 65535;
    unsigned long ul = 4294967295;
    signed char sc = -128;
    unsigned char uc = 255;
    /* long long ll = 9223372036854775807LL;  // Nicht verfügbar in C89 */
    unsigned short us = 65535;
    signed short ss = -32768;
    /* unsigned long long ull = 18446744073709551615ULL;  // Nicht verfügbar in C89 */
    signed int si = -2147483648;
    signed long sl = -2147483648L;
    /* Zeigerdefinition */
    const char* s = "Hallo";

    /* Ausgabe der Variableninformationen */
    printf("Adresse\t\t| Platzbedarf\t| Typ\t\t\t| Name\t\t| Wert\n");
    
    printf("%p\t| %lu\t\t| %s\t\t\t| %s\t\t| %d\n",
    (void*)&i, (unsigned long)sizeof(int), "int", "i", i);
    
    printf("%p\t| %lu\t\t| %s\t\t\t| %s\t\t| %ld\n",
    (void*)&l, (unsigned long)sizeof(long), "long", "l", l);
    
    printf("%p\t| %d\t\t| %s\t\t\t| %s\t\t| %c\n",
    (void*)&c, (int)sizeof(char), "char", "c", c);
    
    printf("%p\t| %lu\t\t| %s\t\t\t| %s\t\t| %f\n",
    (void*)&f, (unsigned long)sizeof(float), "float", "f", (double)f);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %f\n",
    (void*)&d, (unsigned long)sizeof(double), "double", "d", d);
    
    printf("%p\t| %lu\t\t| %s\t\t\t| %s\t\t| %hd\n",
    (void*)&sh, (unsigned long)sizeof(short), "short", "sh", sh);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %u\n",
    (void*)&ui, (unsigned long)sizeof(unsigned int), "unsigned int", "ui", ui);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %lu\n",
    (void*)&ul, (unsigned long)sizeof(unsigned long), "unsigned long", "ul", ul);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %d\n",
    (void*)&sc, (int)sizeof(signed char), "signed char", "sc", sc);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %u\n",
    (void*)&uc, (unsigned long)sizeof(unsigned char), "unsigned char", "uc", uc);

/*  printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %lld\n",
    (void*)&ll, (unsigned long)sizeof(long long), "long long", "ll", ll);  
    // Nicht verfügbar in C89 */
    
    printf("%p\t| %lu\t\t| %s\t| %s\t\t| %hu\n",
    (void*)&us, (unsigned long)sizeof(unsigned short), "unsigned short", "us", us);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %hd\n",
    (void*)&ss, (unsigned long)sizeof(signed short), "signed short", "ss", ss);

/*  printf("%p\t| %lu\t\t| %s\t| %s\t\t| %llu\n",
    (void*)&ull, (unsigned long)sizeof(unsigned long long), "unsigned long long", "ull", ull);  
    // Nicht verfügbar in C89 */
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %d\n",
    (void*)&si, (unsigned long)sizeof(signed int), "signed int", "si", si);
    
    printf("%p\t| %lu\t\t| %s\t\t| %s\t\t| %ld\n",
    (void*)&sl, (unsigned long)sizeof(signed long), "signed long", "sl", sl);
    
    printf("%p\t| %lu\t\t| %s\t\t\t| %s\t\t| %s\n",
    (void*)&s, (unsigned long)sizeof(s), "char*", "s", s);

    return 0;
}
