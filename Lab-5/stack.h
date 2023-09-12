// Stack Functions
#include<stdio.h>
#include<string.h>


#define MAX 100


struct char_stack{
    char data[MAX];
    int top;
};
typedef struct char_stack cstack;

void createStack(cstack *s){
    s->top = -1;
}

int isStackFull(cstack *s){
    if(s->top == MAX-1)
        return(1);
    else
        return(0);
}

int isStackEmpty(cstack *s){
    if(s->top == -1)
        return(1);
    else
        return(0);
}

void pushStack(cstack *s, char data){
    if(isStackFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->data[s->top] = data;
}

void popStack(cstack *s){
    if(isStackEmpty(s)){
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}

void printStack(cstack *s){
    int i;
    for(i=s->top;i>=0;i--){
        printf("%c",s->data[i]);
    }
    printf("\n");
}