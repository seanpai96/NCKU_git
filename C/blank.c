#include <stdio.h>


int main(void) {
    int i = 0;
    while (i > 0)
        ;
    printf("never executed (infinite loop) i=%d\n", i++);



    return 0;
}