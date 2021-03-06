#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}

// Your code goes here

struct data{
    char fruit[15];
    int time;
    int index;
};

int cmp(const void *a, const void *b) {
    struct data *eA = (struct data *)a;
    struct data *eB = (struct data *)b;
    
    if(eA->time > eB->time) return -1;
    if(eA->time < eB->time) return 1;
    if(eA->index < eB->index) return -1;
    if(eA->index > eB->index) return 1;
    return 0;
}

void find_fruit(char input[],char fruit[][15]){
    int times[20] = {0};
    char *token = strtok(input, "+_+");
    while(token){
        for(int i=0;i<20;i++){
            if(strcmp(token, fruit[i]) == 0){
                times[i]++;
            }
        }
        token = strtok(NULL, "+_+");
    }
    struct data a[20];
    for(int i=0;i<20;i++){
        for(int j=0;j<15;j++){
            a[i].fruit[j] = fruit[i][j];
        }
        a[i].time = times[i];
        a[i].index = i;
    }
    qsort(a,20,sizeof(struct data),cmp);
    for(int i=0;i<20;i++){
        if(a[i].time == a[0].time){
            printf("%s\n", a[i].fruit);
        }else{
            break;
        }
        
    }
}