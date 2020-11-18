#include<stdio.h>

int x1,x2,n;

int rec(int a){
    if(a == 1) return x1;
    else if (a == 2) return x2;
    else return (rec(a-1) + rec(a - 2));
}


int main(){
    while(1){
        scanf("%d %d %d", &x1, &x2, &n);
        if(x1 == 0 && x2 == 0 && n == 0) break;
        printf("%d\n", rec(n));
    }
}
