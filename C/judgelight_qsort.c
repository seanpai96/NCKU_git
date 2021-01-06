#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    int level;
    char name[64];
};

int cmp(const void *a, const void *b);
void sort_level(struct ESPer *arr, int length);

int main() {
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }
    putchar('\n');
    sort_level(tokiwadai, n);

    for (int i = 0; i < n; ++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}

int cmp(const void *a, const void *b) {
    struct ESPer *eA = (struct ESPer *)a;
    struct ESPer *eB = (struct ESPer *)b;

    if (eA->level < eB->level) return -1;
    if (eA->level == eB->level) return 0;
    if (eA->level > eB->level) return 1;
}

void sort_level(struct ESPer *arr, int length) {
    qsort(arr, length, sizeof(struct ESPer), cmp);
}
