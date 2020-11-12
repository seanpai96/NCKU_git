#include<stdio.h>
#include<math.h>

int main(){
    int n;
    double a,b,c;
    scanf("%d", &n);

    if(n == 1){
        scanf("%lf", &a);
        printf("%.2lf", a*a*a);
    }else if(n == 2){
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.2lf", a*b*c);
    }else if(n == 3){
        scanf("%lf %lf", &a, &b);
        printf("%.2lf", 3.14*a*a*b);
    }else if(n == 4){
        scanf("%lf", &a);
        double sq = sqrt(2);
        printf("%.2lf", sq/12*a*a*a);
    }

    return 0;
}

