#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


//code for deque
typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}
//deque function end
enum { maxx = 200 };


int arr1[maxx],arr2[maxx];
int arr3[maxx];

int main()
{   
    int n,q;
    scanf("%d %d",&n,&q);
        int i;
        Deque mydeq;
        deq_init(&mydeq);
        int mmax= -1;

        for(i=0;i<n; i++){
            int a;
            scanf("%d",&a);
            deq_pushBack(&mydeq,a);
                if(a>mmax)
                    mmax=a;
        }
        i=0;
            while(1){
                int a = deq_front(&mydeq);

                if(a==mmax)
                    break;

                deq_popFront(&mydeq);

                int b = deq_front(&mydeq);

                deq_popFront(&mydeq);

                arr1[++i] = a;
                arr2[i] = b;
                if(a>b)
                {
                    deq_pushFront(&mydeq,a);
                    deq_pushBack(&mydeq,b);
                }else
                {
                    deq_pushFront(&mydeq,b);
                    deq_pushBack(&mydeq,a);
                }

            }
        int u = i ;
        deq_popFront(&mydeq);
        i = 1 ;
        while(!deq_isEmpty(&mydeq))
        {
            arr3[i] = deq_front(&mydeq);
            deq_popFront(&mydeq);
            i++;
        }
        arr3[0] = arr3[i-1];

        if(q == 0){
                printf("Input Not Valid");
                return 0;
            }else
            {
            for(i=0;i<q;i++)
                {
                long long int m;
                scanf("%lld",&m);
                    if(m>u){
                        m =(m-u)%(n-1);
                        printf("%d %d\n",mmax,arr3[m]);
                    }else
                    {
                    printf("%d %d\n",arr1[m],arr2[m]);   
                    }

                }
        }
  
    return 0;

}




