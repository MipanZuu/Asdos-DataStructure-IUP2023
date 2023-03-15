#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    char data[100];
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value[100]);
void stack_pop(Stack *stack);
char *stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value[100]) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->data, value);
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if(strcmp(stack->_top->data, "Clue") == 0)
    {
        printf("I'm going crazy, right?\n");
    }
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

char *stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void clue_counter(Stack *stack){
    int count=0;
    int p = stack->_size;
    StackNode *temp = stack->_top;
    for(int i = 0; i < p ; i++){
        if(strcmp(temp->data, "Clue")==0){
            count++;
            temp = temp->next;
        }
        else{
            temp = temp->next;
        }
    }
    if(count < 5){
        printf("They keep on asking me, \"Who is he?\"\n");
    }
    if(count >= 5){
        printf("He's the one that's living in my system\n");
    }
}

int main(int argc, char const *argv[])
{
    Stack myStack;
    stack_init(&myStack);

    int n, m;
    char a[100];
    scanf("%d", &n);
    for(int i=0; i < n; i++){
        scanf("%s", a);
        if(strcmp(a, "Clue")==0){
            stack_push(&myStack, a);
        }
        if(strcmp(a, "No")==0){
            char blah[100];
            scanf("%s", blah);
            stack_push(&myStack, a);
        }
    }
    scanf("%d", &m);
    for(int i=0; i < m; i++){
        char b[100];
        scanf("%s", b);
        if(b[0] == 'O'){
            stack_pop(&myStack);
        }
        if(b[0] == 'C'){
            char bleh[100];
            scanf("%s", bleh);
            clue_counter(&myStack);

        }
    }
    puts("");
    return 0;
}