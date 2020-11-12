#include<stdio.h>

int main(){
    int m,n;
    scanf("%d %d", &m,&n);
    int a[m+n];
    int sz = sizeof a / sizeof a[0];
    for(int i=0;i<m;i++)
        scanf("%d", &a[i]);
    for(int i=m;i<(m+n);i++)
        scanf("%d", &a[i]);

    for(int i=0;i<m+n;i++){
        for(int j = i; j<m+n; j++){
            if(a[i] > a[j]){
                int tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }


    for(int i=0;i<(m+n);i++)
        printf("%d ", a[i]);
    return 0;
}

