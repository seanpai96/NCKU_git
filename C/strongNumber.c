#include<stdio.h>

int facto(int a){
    if(a == 0) return 1;
    int result = 1;
    for(int i=2;i<=a;i++) result *= i;
    return result;
}

int main(){
    int a, sum = 0;
    scanf("%d",&a);
    for(int i = a;i != 0; i /= 10){
        int t = i%10;
        sum += facto(t);
    }
    if(a == sum) printf("%d is a strong number.", a);
    else printf("%d is not a strong number.", a);
    return 0;
}

