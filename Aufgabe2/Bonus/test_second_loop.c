#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_second_loop(int n) {
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    clock_t start = clock();
    for (int i = 0; i < n; ++i) {
        int r = rand() % n;
        a[i] = r;
    }
    clock_t end = clock();

    printf("Second loop time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
}

int main() {
    int n = 10000000; // example size
    srand((unsigned int)time(NULL));

    test_second_loop(n);

    return 0;
}