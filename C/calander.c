#include<stdio.h>

int main(){
    int a;
    int firstWeekDay[13] = {0, 3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2};
    int lastDayArr[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &a);
    printf("Sun Mon Tue Wed Thu Fri Sat \n");
    
    int firstDay = firstWeekDay[a];
    for(int i=0;i<firstDay;i++) printf("    ");
    printf("  1 ");
    if(firstDay == 6) printf("\n");
    
    int lastDay = lastDayArr[a];
    int weekDay = (++firstDay) % 7;
    for(int i=2;i <= lastDay;i++){
        printf("%3d ", i);
        if(weekDay == 6 && i != lastDay) printf("\n");
        weekDay = (++weekDay) % 7;
    }
    return 0;
}

