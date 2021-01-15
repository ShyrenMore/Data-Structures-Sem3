#include <stdio.h>
#include <math.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int ch)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        top = top + 1;
        stack[top] = ch;
    }
}

int pop()
{
    int temp;
    if (top == -1)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        temp = stack[top];
        top = top - 1;
    }
    return temp;
}

void calc(char ch, int n2, int n1)
{
    int result;
    switch (ch)
    {
    case '+':
        result = n1 + n2;
        break;
    case '-':
        result = n1 - n2;
        break;
    case '*':
        result = n1 * n2;
        break;
    case '/':
        result = n1 / n2;
        break;
    case '%':
        result = n1 % n2;
        break;
    case '^':
    case '$':
        result = pow(n1, n2);
    }
    push(result);
}

int main()
{
    int i, n1, n2, num;
    char postfix[MAX], ans, ch;
    printf("\n Enter the postfix expression : ");
    scanf("%s", postfix);
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '$')
        {
            n1 = pop();
            n2 = pop();
            calc(ch, n1, n2);
        }
        else
        {
            num = ch - '0';
            push(num);
        }
    }
    printf("\n Postfix expression : %d\n", pop());
    return 0;
}