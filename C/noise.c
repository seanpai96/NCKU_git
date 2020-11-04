#include<stdio.h>
#include<stdlib.h>

int max(int a, int b) {
  if (a>b)
    return a;
  else
    return b;
}

int main(){
    int a[12], ans = -1;
    for(int i=1;i<11;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<11;i++){
        for(int j=1;j<11;j++){
            ans = max(ans, ((a[i] + a[j]) * abs(i-j)));
        }
    }
    printf("%d", ans);
    return 0;
}

