#include<stdio.h>

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int n;
    char c[1001];
    scanf("%d\n", &n);
    for(int i=n-1;i>=0;i--) c[i] = getchar();
    for(int i=0; i<n;i++) printf("%c", c[i]);
    return 0;
}

