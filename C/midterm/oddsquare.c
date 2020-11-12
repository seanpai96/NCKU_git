#include<stdio.h>

int main(){
    int a[50][50] = {0}, n;
    scanf("%d", &n);
    int nowX = 0, nowY = n/2;
    a[nowX][nowY] = 1;
    for(int i=2;i<=n*n;i++){
        int nextX, nextY;
        if((nowX-1) < 0){
            nextX = n-1;
        }else{
            nextX = nowX-1;
        }
        if((nowY+1) > n-1){
            nextY = 0;
        }else{
            nextY = nowY+1;
        }

        if(a[nextX][nextY] != 0){
            if(nowX+1 > n-1){
                nextX = 0;
            }else{
                nextX = nowX + 1;
            }
            nextY = nowY;
        }
        a[nextX][nextY] = i;
        nowX = nextX;
        nowY = nextY;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

