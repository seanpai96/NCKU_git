#include<stdio.h>

void print(int* a, int n){
    int sum = 0;
    for (int i = 0; i < n;i++){
        sum += a[i];
    }
    printf("%d\n", sum);
}

int main(){
    int array[101];
    for (int i = 0; i < 5;i++){
        scanf("%d", &array[i]);
    }
    print(array, 5);
    return 0;
}