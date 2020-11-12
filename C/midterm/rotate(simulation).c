#include<stdio.h>

int main(){
    int a[101][101],m,n, deg;
    scanf("%d", &deg);
    scanf("%d %d", &m, &n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);

    if(deg == 90){
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
    }else if(deg == 180){
        for(int i=m-1;i>=0;i--){
            for(int j = n-1; j>=0;j--){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }else if(deg == 270){
        for(int i=n-1;i>=0;i--){
            for(int j = 0; j<m;j++){
                printf("%d ", a[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}


