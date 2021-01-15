#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue // is just a node pointing to rear and front
{
    node *front;
    node *rear;
} queue;

void initialise(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int data);
int dequeue(queue *q);
void display(queue *q);
int peek(queue *q);

int main()
{
    queue q;
    int data, i, op, deleteEl ,c=1;
    initialise(&q);
    while(c)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4.Peek(display front value) \n5. Exit\n\nEnter your choice :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter data :: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;
        case 2:
            deleteEl = dequeue(&q);
            printf("\n%d was deleted !!", deleteEl);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            data = peek(&q);
            if(data != -1)
                printf("\nThe value at front of queue is %d", data);
            break;
        case 5:
            c = 0;
            break;
        default:
            printf("\nInvalid input");
            break;
        }
    }

    return 0;
}

void initialise(queue* q)
{
    q->front = NULL;
    q->rear = NULL;     
}

void enqueue(queue *q, int value)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = NULL;

    if(isEmpty(q))
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else 
    {
        (q->rear)->next = ptr;
        q->rear = ptr;
    }
}

int dequeue(queue *q)
{
    int value;
    node *ptr;

    if (q->front == NULL)
    {
        printf("\n UNDERFLOW");
        return 0;
    }
    else 
    {
        ptr = q->front;
        value = ptr->data;
        if(q->front == q->rear)     // deleting last element of queue
            initialise(q);
        else
            q->front = ptr->next;
        free(ptr);
        return value;
    }
}

void display(queue *q)
{
    int i;
    node *ptr;
    ptr = q->front;
    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(queue *q)
{
    if(q->rear == NULL)
        return 1;
    return 0;
}

int peek(queue *q)
{
    if (q->front == NULL)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
        return q->front->data;
}