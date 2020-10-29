#include<stdio.h>

int main(){
    int a,b;
    scanf("%d, %d", &a, &b);
    for(int i=0;a>0&&b>0;i++){
        int attack;
        scanf("%d", &attack);
        if(i%2){        //a
            a -= attack;
        }else{
            b -= attack;
        }
    }
    if(a <= 0){
        printf("B");
    }else{
        printf("A");
    }
    return 0;
}


