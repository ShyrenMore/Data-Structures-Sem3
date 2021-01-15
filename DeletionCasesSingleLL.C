#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
/*

typedef 10 MAX;

printf(MAX);
*/
node *create(node *head);
node *display(node *head);
node *deleteAtBeg(node *head);
node *deleteAtEnd(node *head);
node *deleteNode(node *head);
node *deleteAfter(node *head);
node *deleteList(node *head);
node *sortList(node *head);
int main()
{
    node *head = NULL;
    int op;
    while(1)
    {
        printf("\n1. Create LL \n2. Display \n3. Delete node at beg \n4. Delete node at end \n5. Delete a certain a node \n6. Delete the list \n7. Sorting \n8. Exit\n");

        printf("Enter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = deleteAtBeg(head);
            break;
        case 4:
            head = deleteAtEnd(head);
            break;
        case 5:
            head = deleteNode(head);
            break;
        case 6:
            head = deleteList(head);
            break;
        case 7:
            head = sortList(head);
            break;
        case 8: 
            exit(0);
        }
    } 
    return 0;
}

node *create(node *head)
{
    node *newNode;
    node *ptr;

    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");

    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (node *)malloc(sizeof(node));
        newNode->data = num;

        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode; // making newNode head of linkedlist
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = NULL;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return head; // add of head
}

node *display(node *head)
{
    node *ptr;
    if (head == NULL)
    {
        printf("List is empty!!!");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%d--->", ptr->data);
            ptr = ptr->next;
        }
        printf("%d--->NULL", ptr->data);
    }
    return head;
}

node *deleteAtBeg(node *head)
{
    node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

node *deleteAtEnd(node *head)
{
    node *ptr, *preptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return head;
}

node *deleteNode(node *head)
{
    node *ptr, *preptr;
    int value;
    printf("\nEnter the value of node which has to be deleted :: ");
    // printf("\n ");
    scanf("%d", &value);

    ptr = head;
    if (ptr->data == value)
    {
        head = deleteAtBeg(head);
        return head;
    } 
    else
    {
        while (ptr->data != value)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return head;
    }
}

node *deleteAfter(node *head)
{
    node *ptr, *preptr;
    int value;
    printf("\n Enter the value after which the node has to deleted :: ");
    scanf("%d", &value);

    ptr = head;
    preptr = ptr;

    while (preptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return head;
}

node *deleteList(node *head)
{
    node *ptr;
    if (head != NULL)
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("\n%d is to be deleted next !! ", ptr->data);
            head = deleteAtBeg(ptr);
            ptr = head;
        }
    }
    return head;
}

node *sortList(node *head)
{
    node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        // printf("here");
        ptr1 = ptr1->next;
    }
    return head;
}