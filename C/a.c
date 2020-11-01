#include<stdio.h>

int main(){
    int input,sum=0,digit=1,count=0,flag=0;
    scanf("%d",&input);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");
    int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<(input-1);i++){
     sum+=a[i];
    }
    sum+=4;
    sum%=7;
    for(int i=1;i<=a[input-1];i++){
        if(sum==0)sum=7;
        if(flag==0){
            for(int j=1;j<sum;j++){
             printf("    ");
             count++;
         }
            printf("  ");
            flag=1;
        }
     if(i<9&&((count%7)!=6)){
         printf("%d   ",i);
            count++;
        }else if((i!=a[input-1])&&((count%7)!=6)){
            printf("%d  ",i);
   count++;
        }else if((count%7)!=6){
            printf("%d ",i);
           count++;
        }else{
         printf("%d",i); 
            count++;
        }    
        if(((count%7)==0)&&(i<9)){
            printf(" \n  ");
        }else if(((count%7)==0)&&(i!=a[input-1])){
         printf(" \n ");
        }
    }
    
    return 0;
}
