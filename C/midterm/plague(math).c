#include<stdio.h>
#include<math.h>

int main(){
    double r,n;
    double a = 1.0;
    scanf("%lf %lf", &r, &n);

    for(int i=0;i<n;i++) a *= r;

    int ans = floor(a);
    printf("%d", ans);
    return 0;
}

