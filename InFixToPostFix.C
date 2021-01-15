#include <stdio.h>
#define max 100

struct stack
{
    char a[max];
    int top;
};

void initialize(struct stack *s)
{
    s->top = -1;
}

int isEmpty(struct stack *s)
{
    return s->top == -1;
}

int isFull(struct stack *s)
{
    return s->top == (max - 1);
}

void push(struct stack *s, char x)
{
    if (!isFull(s))
        s->a[++s->top] = x;
}

void pop(struct stack *s)
{
    if (!isEmpty(s))
        --s->top;
}

char top(struct stack *s)
{
    return s->a[s->top];
}

int precedence(char x)
{
    if (x == '^' || x == '$')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main()
{
    int j = 0;
    char infix[100], postfix[100];
// (a+b)*c - infix
// postfix - a
// stack - ( , 
    struct stack st;
    initialize(&st);
    printf("Enter the infix expression: ");
    scanf("%s", &infix);

    for (int i = 0; infix[i] != 0; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(&st, '(');
        else if (infix[i] == ')')
        {
            while (top(&st) != '(')
            {
                postfix[j++] = top(&st);
                pop(&st);
            }
            pop(&st);
        }
        else
        {
            while (!isEmpty(&st))
            {
                if (precedence(infix[i]) <= precedence(top(&st)))
                {
                    postfix[j++] = top(&st);
                    pop(&st);
                }
                else
                    break;
            }
            push(&st, infix[i]);
        }
    }

    while (!isEmpty(&st))
    {
        postfix[j++] = top(&st);
        pop(&st);
    }
    postfix[j] = 0;
    printf("Postfix string is %s", postfix);
    return 0;
}

/*
output 
Enter the infix expression: (a*b+c)/d+e
Postfix string is ab*c+d/e+
*/