#include <stdio.h>
#include <inttypes.h> // Für die Verwendung der PRId8, PRId16, usw. Formatangaben
#include <stdint.h> // Für die Verwendung der int8_t, int16_t, usw. Typen

int main()
{
    // Definition und Initialisierung der Variablen mit den größten darstellbaren Zahlen
    int8_t i8 = INT8_MAX;
    int16_t i16 = INT16_MAX;
    int32_t i32 = INT32_MAX;
    int64_t i64 = INT64_MAX;
    int_fast8_t i_fast8 = INT_FAST8_MAX;
    int_fast16_t i_fast16 = INT_FAST16_MAX;
    int_fast32_t i_fast32 = INT_FAST32_MAX;
    int_fast64_t i_fast64 = INT_FAST64_MAX;
    int_least8_t i_least8 = INT_LEAST8_MAX;
    int_least16_t i_least16 = INT_LEAST16_MAX;
    int_least32_t i_least32 = INT_LEAST32_MAX;
    int_least64_t i_least64 = INT_LEAST64_MAX;
    intmax_t intmax = INTMAX_MAX;
    intptr_t intptr = INTPTR_MAX;
    uint8_t u8 = UINT8_MAX;
    uint16_t u16 = UINT16_MAX;
    uint32_t u32 = UINT32_MAX;
    uint64_t u64 = UINT64_MAX;
    uint_fast8_t u_fast8 = UINT_FAST8_MAX;
    uint_fast16_t u_fast16 = UINT_FAST16_MAX;
    uint_fast32_t u_fast32 = UINT_FAST32_MAX;
    uint_fast64_t u_fast64 = UINT_FAST64_MAX;
    uint_least8_t u_least8 = UINT_LEAST8_MAX;
    uint_least16_t u_least16 = UINT_LEAST16_MAX;
    uint_least32_t u_least32 = UINT_LEAST32_MAX;
    uint_least64_t u_least64 = UINT_LEAST64_MAX;
    uintmax_t uintmax = UINTMAX_MAX;
    uintptr_t uintptr = UINTPTR_MAX;

    // Ausgabe der Variableninformationen
    printf("Adresse\t\t| Platzbedarf\t| Typ\t\t\t| Name\t\t| Wert\n");
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRId8 "\n",
    (void*)&i8, (int)sizeof(int8_t), "int8_t", "i8", i8);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRId16 "\n",
    (void*)&i16, (int)sizeof(int16_t), "int16_t", "i16", i16);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRId32 "\n",
    (void*)&i32, (int)sizeof(int32_t), "int32_t", "i32", i32);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRId64 "\n",
    (void*)&i64, (int)sizeof(int64_t), "int64_t", "i64", i64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdFAST8 "\n",
    (void*)&i_fast8, (int)sizeof(int_fast8_t), "int_fast8_t", "i_fast8", i_fast8);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdFAST16 "\n",
    (void*)&i_fast16, (int)sizeof(int_fast16_t), "int_fast16_t", "i_fast16", i_fast16);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdFAST32 "\n",
    (void*)&i_fast32, (int)sizeof(int_fast32_t), "int_fast32_t", "i_fast32", i_fast32);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdFAST64 "\n",
    (void*)&i_fast64, (int)sizeof(int_fast64_t), "int_fast64_t", "i_fast64", i_fast64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdLEAST8 "\n",
    (void*)&i_least8, (int)sizeof(int_least8_t), "int_least8_t", "i_least8", i_least8);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdLEAST16 "\n",
    (void*)&i_least16, (int)sizeof(int_least16_t), "int_least16_t", "i_least16", i_least16);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdLEAST32 "\n",
    (void*)&i_least32, (int)sizeof(int_least32_t), "int_least32_t", "i_least32", i_least32);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdLEAST64 "\n",
    (void*)&i_least64, (int)sizeof(int_least64_t), "int_least64_t", "i_least64", i_least64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdMAX "\n",
    (void*)&intmax, (int)sizeof(intmax_t), "intmax_t", "intmax", intmax);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIdPTR "\n",
    (void*)&intptr, (int)sizeof(intptr_t), "intptr_t", "intptr", intptr);
    // unsigned integer type

    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRIu8 "\n",
    (void*)&u8, (int)sizeof(uint8_t), "uint8_t", "u8", u8);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRIu16 "\n",
    (void*)&u16, (int)sizeof(uint16_t), "uint16_t", "u16", u16);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRIu32 "\n",
    (void*)&u32, (int)sizeof(uint32_t), "uint32_t", "u32", u32);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t\t| %" PRIu64 "\n",
    (void*)&u64, (int)sizeof(uint64_t), "uint64_t", "u64", u64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuFAST8 "\n",
    (void*)&u_fast8, (int)sizeof(uint_fast8_t), "uint_fast8_t", "u_fast8", u_fast8);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuFAST16 "\n",
    (void*)&u_fast16, (int)sizeof(uint_fast16_t), "uint_fast16_t", "u_fast16", u_fast16);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuFAST32 "\n",
    (void*)&u_fast32, (int)sizeof(uint_fast32_t), "uint_fast32_t", "u_fast32", u_fast32);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuFAST64 "\n",
    (void*)&u_fast64, (int)sizeof(uint_fast64_t), "uint_fast64_t", "u_fast64", u_fast64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuLEAST8 "\n",
    (void*)&u_least8, (int)sizeof(uint_least8_t), "uint_least8_t", "u_least8", u_least8);
    
    printf("%p\t| %d\t\t| %s\t| %s\t| %" PRIuLEAST16 "\n",
    (void*)&u_least16, (int)sizeof(uint_least16_t), "uint_least16_t", "u_least16", u_least16);
    
    printf("%p\t| %d\t\t| %s\t| %s\t| %" PRIuLEAST32 "\n",
    (void*)&u_least32, (int)sizeof(uint_least32_t), "uint_least32_t", "u_least32", u_least32);
    
    printf("%p\t| %d\t\t| %s\t| %s\t| %" PRIuLEAST64 "\n",
    (void*)&u_least64, (int)sizeof(uint_least64_t), "uint_least64_t", "u_least64", u_least64);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuMAX "\n",
    (void*)&uintmax, (int)sizeof(uintmax_t), "uintmax_t", "uintmax", uintmax);
    
    printf("%p\t| %d\t\t| %s\t\t| %s\t| %" PRIuPTR "\n",
    (void*)&uintptr, (int)sizeof(uintptr_t), "uintptr_t", "uintptr", uintptr);

    return 0;
}
