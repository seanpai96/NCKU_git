#include<stdio.h>

int main(){
    int a[32], b[32], result[32];
    for(int i=0;i<32;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<32;i++){
        scanf("%d", &b[i]);
    }
    int addup = 0;
    for(int i=31; i>=0;i--){
        int tmp = a[i] + b[i] + addup;
        if(tmp >= 2){
            addup = 1;
            result[i] = tmp - 2;
        }else{
            addup = 0;
            result[i] = tmp;
        }
    }
    for(int i=0;i<32;i++){
        printf("%d ", result[i]);
    }
    return 0;
}

