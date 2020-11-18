#include<stdio.h>

long long c(long long n, long long m){
    if(m == 0 || m == n) return 1;
    else return c(n-1,m-1) + c(n-1,m);
}


int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld", c(n,m));
}
