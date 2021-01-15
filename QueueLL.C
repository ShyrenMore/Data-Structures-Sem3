/*
The START pointer of the linked list is used as FRONT. Here, we will
also use another pointer called REAR, which will store the address of the last element in the queue.
All insertions will be done at the rear end and all the deletions will be done at the front end. If
FRONT = REAR = NULL, then it indicates that the queue is empty.

Each element is stored in a node 
node will have two fields data and next which stores address of next node in queue
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct queue    // is just a node pointing to rear and front 
{
    node *front;
    node *rear;
} queue;

void create_queue(queue *q);
queue *insert(queue *q, int val);
queue *delete_element(queue *q);
queue *display(queue *q);
int peek(queue *q);

int main()
{
    int val, op, c = 1;
    queue *q;
    // printf("up here");
    create_queue(q);
    printf("here");
    while(c)
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n Enter the number to insert in the queue:");
            scanf("%d", &val);
            q = insert(q, val);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = peek(q);
            if (val!=-1)
                printf("\n The value at front of queue is : %d", val);
            break;
        case 4:
            q = display(q);
            break;
        case 5:
            c = 0;
        default:
            printf("Invalid option");
            break;
        }
    }
    return 0;
}

void create_queue(queue *q)
{
    q->rear = NULL;
    q->front = NULL;
}
queue *insert(queue *q, int val)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = q->rear->next = NULL;
    }
    else
    {
        (q->rear)->next = ptr;
        q->rear = ptr;
        (q->rear)->next = NULL;
    }
    return q;
}
queue *display(queue *q)
{
    node *ptr;
    ptr = q->front;
    if (ptr == NULL)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\n");
        while (ptr != q->rear)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\t", ptr->data);
    }
    return q;
}
queue *delete_element(queue *q)
{
    node *ptr;
    ptr = q->front;
    if (q->front == NULL)
        printf("\n UNDERFLOW");
    else
    {
        q->front = q->front->next;
        printf("\n The value being deleted is : %d", ptr->data);
        free(ptr);
    }
    return q;
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