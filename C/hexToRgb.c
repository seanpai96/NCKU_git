#include<stdio.h>
#include<math.h>

int main(){
    getchar();

    //r
    char c1,c2;
    int r = 0;
    c1 = getchar();
    c2 = getchar();
    if(c1 >= 'A' && c1 <= 'F'){
        int a = c1 - 'A' + 10;
        r += 16*a;
    }else{
        r += 16*(c1-'0');
    }
    if(c2 >= 'A' && c2 <= 'F'){
        int a = c2 - 'A' + 10;
        r += a;
    }else{
        r += (c2-'0');
    }

    //g
    int g = 0;
    c1 = getchar();
    c2 = getchar();
    if(c1 >= 'A' && c1 <= 'F'){
        int a = c1 - 'A' + 10;
        g += 16*a;
    }else{
        g += 16*(c1-'0');
    }
    if(c2 >= 'A' && c2 <= 'F'){
        int a = c2 - 'A' + 10;
        g += a;
    }else{
        g += (c2-'0');
    }

    //b
    int b = 0;
    c1 = getchar();
    c2 = getchar();
    if(c1 >= 'A' && c1 <= 'F'){
        int a = c1 - 'A' + 10;
        b += 16*a;
    }else{
        b += 16*(c1-'0');
    }
    if(c2 >= 'A' && c2 <= 'F'){
        int a = c2 - 'A' + 10;
        b += a;
    }else{
        b += (c2-'0');
    }

    printf("rgb(%d,%d,%d)", r,g,b);
    return 0;
}


