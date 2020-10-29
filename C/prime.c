#include<stdio.h>

void prime(int a){
    if(a == 1) {
        printf("1 ");
        return;
    }
    for(int i=2;i*i<a;i++) 
        if(a%i == 0) 
            return;
    printf("%d ", a);
    return;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    for(int i=a;i<=b;i++){
        prime(i);
    }
    return 0;
}
