#include <stdio.h>
#include <string.h>

void add(char a[], char b[], char res[]);

int main() {
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}

// Your code goes here

void add(char a[], char b[], char res[]) {
    int lenA = strlen(a), lenB = strlen(b), aBig = lenA > lenB ? 1 : 0, mx;
    char revA[101], revB[101], revRes[105];

    for (int i = 0; i < 105; i++) revRes[i] = '0';
    for (int i = 0; i < 101; i++) revA[i] = '0', revB[i] = '0';

    for (int i = 0; i < lenA; i++) {
        revA[i] = a[lenA - i - 1];
    }
    for (int i = 0; i < lenB; i++) {
        revB[i] = b[lenB - i - 1];
    }
    if (aBig) {
        mx = lenA;
        revA[lenA] = '0';
    } else {
        mx = lenB;
        revA[lenB] = '0';
    }
    int carry = 0;
    for (int i = 0; i <= mx; i++) {
        int numA = revA[i] - '0', numB = revB[i] - '0', sum;
        sum = numA + numB + carry;
        carry = sum / 10;
        revRes[i] = (sum % 10) + '0';
    }

    int i, j;
    for (i = mx; i > 0 && revRes[i] == '0'; --i);
    for (j = 0; i >= 0; j++, i--) {
        res[j] = revRes[i];
    }
    res[j] = '\0';
}