#include <stdio.h>
#include <stdlib.h>
#define n 8

// Ignore this
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)) { exit(1); }
// Ignore this

void quicksort(int a[], int low, int high);
int main(void) {
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

void quicksort(int a[], int low, int high) {
    for (int *p = a; p < a + high + 1; p++){
        for (int *q = p; q < a + high + 1; q++){
            int tmp;
            if(*p>*q){
                tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }
    }
}
