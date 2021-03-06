#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
    "Juice",
    "Wine",
    "Laptop"
};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main(){
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while(fgets(record, 64, stdin)){
        job = strtok(record, " ");
        if(!strcmp(job, "Produce")){
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for(int i = 0; i < 3; i++){
                if(!strcmp(good, good_types[i])){
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if(!strcmp(job, "Consume")){
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
// Your code goes here
//You may need to define your own struct here.

struct item {
    const char* name;
    size_t qty;
    struct item* next;
};

void *produce(void *top_of_stack, const char *good_type, const size_t count){
    if(top_of_stack != NULL){
        struct item* current = (struct item*) top_of_stack;
        if(strcmp(current->name, good_type) == 0){
            current->qty += count;
            return current;
        }
    }
    struct item* new;
    new = malloc(sizeof(struct item));
    new->qty = count;
    new->name = good_type;
    new->next = top_of_stack;
    return new;
}

void *consume(void *top_of_stack, const size_t count){
    size_t remain = count;
    struct item* current = (struct item*) top_of_stack;
    while(remain>0){
        if(current->qty > remain){
            size_t tmp = remain;
            remain = 0;
            current->qty -= tmp;
        }else{
            remain -= current->qty;
            current = current->next;
        }
    }
    return current;
}

void list_remain(void *top_of_stack){
    if(top_of_stack == NULL){
        printf("Empty\n");
        return;
    }
    for(struct item* cur = top_of_stack; cur != NULL; cur = cur->next){
        printf("%s x %zu\n", cur->name, cur->qty);
    }
}
