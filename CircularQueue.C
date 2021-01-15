#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int deleteElement(void);
int peek(void);
void display(void);

int main()
{
    int op, val, c=1;
    while (1)
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            val = deleteElement();
            if (val != -1)
                printf("\nNumber deleted is %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\nThe first value in queue is %d", val);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input");
        }
    }
    return 0;
}

void insert()
{
    int num;
    if (rear == MAX - 1 && front == 0)
    {
        printf("\nOverflow");
    }
    else 
    {
        printf("\nEnter number to be inserted in queue :: ");
        scanf("%d", &num);
        if(front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = num;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = (rear + 1) % MAX;
            queue[rear] = num;
        }
        else 
        {
            rear++;
            queue[rear] = num;
        }
        
        /*
        else 
        {
            rear++;
            queue[rear] = num;
        }
        */
    }
}

int deleteElement()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\nUNDERFLOW");
        return -1;
    }
    val = queue[front];
    if(front == rear)
        front = rear = -1;
    else
    {
        if(front == MAX-1)
            front = 0;
        else
            front++;
    }
    return val;
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
        printf("\n QUEUE IS EMPTY");
    else
    {
        if(front < rear)
            for (i = front; i <= rear; i++)
                printf("\t% d", queue[i]);
        else
        {
            for (i = front; i < MAX; i++)
                printf("\t%d", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("\t%d", queue[i]);
        }
    }
}