#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *push(stack*, int);
stack *pop(stack *);
stack *display(stack *);
int peek(stack *);

int main()
{
    int val, op;
    stack *top = NULL;
    while (1)
    {
        printf("\n1. Push \n2. Pop \n3. Peek \n4. Display\n5. Exit\n");

        printf("Enter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter number to be pushed inside stack: ");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
                printf("\n The value at the top of stack is: %d", val);
            else
                printf("\n STACK IS EMPTY");
            break;
        case 4:
            top = display(top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}

struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}

struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK IS EMPTY");
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d\n|\n|\nv", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}

struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n STACK UNDERFLOW");
    else
    {
        top = top->next;
        printf("\n The value being deleted is: %d", ptr->data);
        free(ptr);
    }
    return top;
}
int peek(struct stack *top)
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}

