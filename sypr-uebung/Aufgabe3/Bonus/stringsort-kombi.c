#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubblesort(char **a, int n) {
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                char *tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s number_of_elements\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1) {
        fprintf(stderr, "Number of elements must be at least 1\n");
        return 1;
    }

    char **a = (char **)malloc(n * sizeof(char *));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Calculate the total memory required for storing the strings
    int total_length = 0;
    for (int i = 0; i < n; ++i) {
        total_length += snprintf(NULL, 0, "%d", i) + 1; // +1 for the null terminator
    }

    char *buffer = (char *)malloc(total_length * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(a);
        return 1;
    }

    srand((unsigned int)time(NULL));
    printf("Unsorted array:\n");
    char *current_position = buffer;
    for (int i = 0; i < n; ++i) {
        int r = rand() % n;
        a[i] = current_position;
        int length = snprintf(current_position, total_length, "%d", r);
        current_position += length + 1; // Move to the next position in the buffer
        printf("%s ", a[i]);
    }
    printf("\n");

    bubblesort(a, n);

    printf("Sorted array:\n");
    printf("%s", a[0]);
    for (int i = 1; i < n; ++i) {
        if (strcmp(a[i], a[i - 1]) == 0) {
            printf("*");
        } else {
            printf(" %s", a[i]);
        }
    }
    printf("\n");

    free(buffer);
    free(a);

    return 0;
}
