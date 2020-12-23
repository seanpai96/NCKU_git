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
    return 0;
}

void sort_level(struct ESPer *arr, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if(arr[i].level > arr[j].level){
                struct ESPer tmp;
                tmp.level = arr[i].level;
                for (int noStringH = 0; noStringH < 64;noStringH++){
                   tmp.name[noStringH] = arr[i].name[noStringH];
                }

                arr[i].level = arr[j].level;
                for (int noStringH = 0; noStringH < 64; noStringH++) {
                   arr[i].name[noStringH] = arr[j].name[noStringH];
                }

                arr[j].level = tmp.level;
                for (int noStringH = 0; noStringH < 64; noStringH++) {
                    arr[j].name[noStringH] = tmp.name[noStringH];
                }
            }
        }
    }
}
