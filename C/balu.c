#include<stdio.h>

long long b(long long i){
    if(i <= 2) return 1;
    else return (2*b(i-1)+3*b(i-2)) % 1000000007;
}

int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld", b(n));
}
