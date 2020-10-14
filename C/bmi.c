#include<stdio.h>
#include<math.h>

int main(){
    double weight, mHeight;
    scanf("%le %le", &weight, &mHeight);
    double bmi = (weight*1.0) / (mHeight*mHeight);
    bmi = round(bmi*10) / 10.0;
    printf("%.1f", bmi);
}
