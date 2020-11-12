#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
}



int main(){
    //int a[100001];
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


    //qsort(a, sz, sizeof(int), cmp);
    for(int i=0;i<(m+n);i++)
        printf("%d ", a[i]);
    return 0;
}

