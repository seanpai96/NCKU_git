#include<stdio.h>

int rec(int n, int m){
    if(n == 0) return m+1;
    else if (m == 0) return rec(n-1, 1);
    else return rec(n-1, rec(n,m-1));
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    printf("%d", rec(n,m));
}
