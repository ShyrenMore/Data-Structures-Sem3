#include <stdio.h>
#define MAX 100
int stack[MAX];

int top = -1;
int pop();
void push(int);

int main()
{
    int val, n, i;
    int temp[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enetr elements of array: ");
    for ( i = 0; i < n; i++)
        scanf("%d", &temp[i]);
    for ( i = 0; i < n; i++)
        push(temp[i]);
    for ( i = 0; i < n; i++)
        temp[i] = pop();

    printf("reverse array is: ");
    for ( i = 0; i < n; i++)
        printf("%d\t", temp[i]);

    return 0;
}

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return (stack[top--]);
}