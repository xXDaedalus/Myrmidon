#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Comparison function for qsort
int compare(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s number_of_elements\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1)
    {
        fprintf(stderr, "Number of elements must be at least 1\n");
        return 1;
    }

    // Calculate maximum string length (including null terminator)
    int max_string_length = snprintf(NULL, 0, "%d", n - 1) + 1;
    size_t total_size = n * max_string_length;

    // Allocate contiguous memory block for all strings
    char *block = (char *)malloc(total_size);
    if (block == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    printf("Unsorted array:\n");
    for (int i = 0; i < n; ++i)
    {
        int r = rand() % n;
        snprintf(block + i * max_string_length, max_string_length, "%d", r);
        printf("%s ", block + i * max_string_length);
    }
    printf("\n");

    // Use qsort to sort the strings
    qsort(block, n, max_string_length, compare);

    printf("Sorted array:\n");
    printf("%s", block);
    for (int i = 1; i < n; ++i)
    {
        if (strcmp(block + i * max_string_length, block + (i - 1) * max_string_length) == 0)
        {
            printf("*");
        }
        else
        {
            printf(" %s", block + i * max_string_length);
        }
    }
    printf("\n");

    free(block);

    return 0;
}
