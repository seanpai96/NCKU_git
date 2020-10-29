#include<stdio.h>

int main(){
    int n;
    scanf("%d\n", &n);
    if (n < 0) {
        n = 26 + (n % 26);
    }
    char c;
    for(c = getchar(); c != '\n'; c = getchar()){
        if(c >= 'A' && c <= 'Z'){
            printf("%c", (((c - 'A') + n )%26)+'A');
        }else if(c >= 'a' && c <= 'z'){
            printf("%c", (((c - 'a') + n )%26)+'a');
        }else{
            printf("%c", c);
        }
    }
    return 0;
}


