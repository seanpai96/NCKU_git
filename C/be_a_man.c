#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(){
    int birth, height, weight;
    scanf("%d %d %d", &birth, &height, &weight);
    int age = 2020-birth+1;
    bool regular = false, sub = false, exc = false;
    double mHeight = height * 0.01;
    double bmi = (weight*1.0) / (mHeight*mHeight);
    bmi = (int)((bmi*10)+0.5) / 10.0;

    printf("Age = %d\nHeight = %dcm\nWeight = %dkg\nBMI = %.1f\n", age, height, weight, bmi);
    
    if(bmi < 16.5 || bmi > 31.5){
        printf("Physical Status of Military Service Exemption\n");
        exc = true;
    }else if((16.5<=bmi && bmi < 17) || (31 < bmi && bmi <= 31.5)){
        printf("Physical Status of Substitute Service Draftees\n");
        sub = true;
    }else if( 17 <= bmi && bmi <= 31 ){
        printf("Physical Status of Regular Service Draftees\n");
        regular = true;
    }

    if(age<19 || age>36){
        printf("No need to perform Military Service");
    }else if(exc){
        printf("Exemption from Military Service");
    }else if(sub){
        if(birth>1993){
            printf("Replacement Service");
        }else{
            printf("Substitute Services");
        }
    }else if(regular){
        if(birth>1993){
            printf("4 months of Regular Service");
        }else{
            printf("1 year of Regular Service");
        }
    }
}
