#include<stdio.h>

__int128 facto(long long n){
    if(n == 0){
        return 1;
    }
    __int128 sum = 1;
    for(int i=2;i<=n;i++){
        sum *= i;
    }
    return sum;
}

int main(){
    unsigned long long m,n;
    scanf("%llu %llu", &m, &n);
    printf("%llu", facto(m)/ (facto(m-n)*facto(n)));
    return 0;
}

