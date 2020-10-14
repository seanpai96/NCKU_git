#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(){
    int birth, height, weight;
    scanf("%d %d %d", &birth, &height, &weight);
    int age = 2020-birth+1;
    double mHeight = height * 0.01;
    double bmi = (weight*1.0) / (mHeight*mHeight);
    bmi = (int)((bmi*10)+0.5) / 10.0;
    printf("Age = %d\nHeight = %dcm\nWeight = %dkg\nBMI = %.1f\n", age, height, weight, bmi);

    if(age<19 || age>36){
        printf("Not a Draftee (age < 19 or age > 36 years old)\nNo need to perform Military Service");
        return 0;
    }

    bool regular = 17 <= bmi && bmi <= 31 , sub = (16.5 <= bmi && bmi < 17) || (31 < bmi && bmi <= 31.5), exc = bmi < 16.5 || bmi > 31.5;

    if(exc) printf("Physical Status of Military Service Exemption\n");
    else if(sub) printf("Physical Status of Substitute Service Draftees\n");
    else if(regular) printf("Physical Status of Regular Service Draftees\n");

    if(exc) printf("Exemption from Military Service");
    else if(sub) if(birth>1993) printf("Replacement Service"); else printf("Substitute Services");
    else if(regular) if(birth>1993) printf("4 months of Regular Service"); else printf("1 year of Regular Service");
}
