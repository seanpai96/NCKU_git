#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char all[721][7];
int k=0;

void f(char* s, int d){
    if(strlen(s) == d){
        for(int i=0;i<7;i++){
            all[k][i] = s[i];
        }
        k++;
    }else{
        for(int i=d; i<strlen(s);i++){
            char cpy[7];
            strcpy(cpy,s);
            char tmp = cpy[d];
            cpy[d] = cpy[i];
            cpy[i] = tmp;
            f(cpy,d+1);
        }
    }

}

int main(void){
    char s[7];
    scanf("%s", s);
    f(s,0);
    for(int i=0;i<k;i++){
        printf("%s\n", all[i]);
    }
    return 0;
}

