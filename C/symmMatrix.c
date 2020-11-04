#include<stdio.h>
#include<stdbool.h>

int a[1001][1001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    bool sym = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != a[j][i])
                sym = false;
        }
    }

    if(sym)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

