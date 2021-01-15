#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Insertion - rear
// deletion - front
// some special conditions
// empty queue front = rear = -1
// full queue, rear = max - 1
// single element in queue, rear = front
// non empty queue, rear > front
int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int deleteElement(void);
int peek(void);
void display(void);

int main()
{
    int op, val;
    while (1)
    {
        printf("\n1. Insert an element\n2. Delete an element\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();   //enqueue
            break;
        case 2:
            val = deleteElement();  //dequeue
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
        }
    }
    return 0;
}
void insert()
{
    int num;
    if (rear != MAX - 1)
    {
        printf("\nEnter number to be inserted in queue :: ");
        scanf("%d", &num);
        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear++;
        queue[rear] = num;
    }
    else
        printf("Overflow!!");
}

int deleteElement()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW");      
        return -1;
    }
    else
    {
        val = queue[front];
        front++;    
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

int peek()
{
    if (front == -1 || front > rear)
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
    if (front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else
    {
        for (i = front; i <= rear; i++)
            printf("\t% d", queue[i]);
    }
}