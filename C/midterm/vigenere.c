#include<stdio.h>

int main(){
    int n, keyp=0, intkey[101];
    char key[101];

    scanf("%d\n", &n);
    for(int i=0;i<n;i++) key[i] = getchar();
    getchar();
    for(int i=0;i<n;i++){
        intkey[i] = key[i] - 'a';
    }

    for(char c = getchar(); c != '\n'; c = getchar()){
        if(c >= 'A' && c <= 'Z'){
            printf("%c", (((c - 'A') + intkey[keyp]) % 26) + 'A');
            keyp = (keyp+1)%n;
        }else if(c >= 'a' && c <= 'z'){
            printf("%c", (((c - 'a') + intkey[keyp]) % 26) + 'a');
            keyp = (keyp+1)%n;
        }else{
            printf("%c", c);
        }
    }

    return 0;
}

