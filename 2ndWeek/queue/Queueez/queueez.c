/*
    Denta Bramasta Hidayat
    20 November 2021
    17.50 WIB
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    Queue myQueue;
    queue_init(&myQueue);
    int t, input, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &input);
        if (input == 1)
        {
            scanf("%d", &n);
            queue_push(&myQueue, n);
        }
        else if (input == 2){
            if (!queue_isEmpty(&myQueue))
            queue_pop(&myQueue);
            
        }
        else if (input == 3) {    
            if (queue_isEmpty(&myQueue))  
                printf("Empty!\n");
            else      
                printf("%d\n", queue_front(&myQueue));
        }  
    }
}