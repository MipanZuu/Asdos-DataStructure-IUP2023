#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#define LL long long

typedef struct stackNode_t {

    LL self;
    LL front;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;

} Stack;

void stack_init(Stack *stack) 

{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}
void stack_push(Stack *stack, LL self, LL front) 

{

    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));

    if (newNode) {

        stack->_size++;

        newNode->self = self;

        newNode->front = front;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;
        stack->_top = newNode;

    }

}



void stack_pop(Stack *stack) 

{
    StackNode *temp = stack->_top;
    stack->_top = stack->_top->next;

    free(temp);

    stack->_size--;

}



LL stack_topSelf(Stack *stack) 

{
    return stack->_top->self;
}



LL stack_topFront(Stack *stack)

{
    return stack->_top->front;
}

unsigned stack_size(Stack *stack) {

    return stack->_size;
}



int main(int argc, char const *argv[])

{

    Stack myStack;
    stack_init(&myStack);
    stack_push(&myStack, LLONG_MAX, 0);
    LL sum = 0;
    LL n, value;
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld", &value);
        while (!stack_isEmpty(&myStack)) {
            if (value >= stack_topSelf(&myStack)) {
                stack_pop(&myStack);
            } else {
                break;
            }
        }
        sum += i - stack_topFront(&myStack);
        stack_push(&myStack, value, i);
    }
    printf("Sum = %lld\n", sum);
    return 0;

}