#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int *a, int n)
{
    for (int i = n; i > 1; --i)
    {
        // Move the largest value to the end
        for (int j = 0; j < i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                // Swap values
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s number_of_elements\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Please enter %d integers: ", n);

    int k = 0;
    while (k < n && scanf("%d", &a[k]) == 1)
    {
        ++k;
    }

    srand((unsigned int)time(NULL));
    for (int i = k; i < n; ++i)
    {
        a[i] = rand();
        printf("%d\n", a[i]);
    }

    bubblesort(a, n);

    printf("Sorted sequence of numbers:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", a[i]);
    }

    free(a);
    return 0;
}
