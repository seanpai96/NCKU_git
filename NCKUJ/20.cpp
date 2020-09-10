#include "lib0020.h"

long long height_limit(long long M){
    long long a, upper_bound = M, lower_bound = 1;
    while(upper_bound > lower_bound){
        a = (upper_bound + lower_bound) / 2;
        if(is_broken(a)){
            upper_bound = a - 1;
        }else{
            lower_bound = a + 1;
        }
    }
    a = (upper_bound + lower_bound) / 2;
    if(is_broken(a)){
        return a - 1;
    }else{
        return a;
    }
}