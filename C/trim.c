#include<stdio.h>
#include<stdbool.h>

int main(){
    bool spaced;
    char c;
    for(c = getchar(); c!='\n';c = getchar()){
        if(c != ' '){
            spaced = false;
            printf("%c", c);
        }else{
            if(spaced){
                continue;
            }else{
                spaced = true;
                printf("%c", c);
            }
        }
    }
    return 0;
}


