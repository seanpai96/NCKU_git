#include<stdio.h>
#include<stdlib.h>

int *a;

void throw(int size){
    printf("%d ", a[0]);
    for(int i=1;i<size;i++){
        a[i-1] = a[i];
    }
}

void move(int size){
    int tmp = a[0];
    for(int i=1;i<size;i++){
        a[i-1] = a[i];
    }
    a[size - 1] = tmp;
}

int main(){
    int m,n;
    scanf("%d %d", &m, &n);
    a = malloc(sizeof(int)*m);
    for(int i=0;i<m;i++){
        a[i] = i+1;
    }
    
    for(int i=0;i<n;i++){
        throw(m);
        m--;
        move(m);
    }
    return 0;
}

