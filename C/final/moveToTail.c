#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
}
// Your code goes here

void MoveToTail() {
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    int max = -100000;
    struct node* largest = NULL;
    for(struct node* cur = head; cur != NULL; cur = cur->next){
        max = cur->val > max ? cur->val : max;
        if(max == cur->val) largest = cur;
    }
    int d = 0;
    for(struct node* cur = head; cur != NULL; cur = cur->next){
        if(cur == largest && d == 0){
            head = cur->next;
        }else if(cur->next == largest){
            cur->next = largest->next;
        }
        if(cur->next == NULL){
            cur->next = largest;
            largest->next = NULL;
        }
        d++;
    }
}