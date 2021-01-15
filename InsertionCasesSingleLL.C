#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(node *head);
node *display(node *head);
node *insertAtBeg(node *head); // data to be inserted after key
node *insertAfterNode(node *head);
node *insertBeforeNode(node *head);
node *insertAtEnd(node *head);

int main()
{
    node *head = NULL;
    int op;
    do
    {
        printf("\n1. Create LL \n2. Add node at beg \n3. Display \n4. Insert After a node\n5. Insert Before a node \n6. Insert at end \n7. Exit\n");

        printf("Enter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            head = insertAtBeg(head);
            break;
        case 3:
            head = display(head);
            break;
        case 4:
            head = insertAfterNode(head);
            break;
        case 5:
            head = insertBeforeNode(head);
        case 6:
            head = insertAtEnd(head);
        }
    } while (op != 7);
    return 0;
}

node* create(node *head)
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
    ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d--->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d--->NULL", ptr->data);
    return head;
}

/*
int add(int n1, int n2)
{
    int c = n1 + n2;
    return c;
}
*/

node* insertAtBeg(node* head)
{
    node* newNode;
    int num;
    printf("Enter data: "); // <---
    scanf("%d", &num);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = head; // next should point to wherever head is currently pointing
    // now update head with newNode's address
    // newNode->next = &head;
    head = newNode;
    return head;
}

/*

0) obtain data and after what value it is to be inserted
1) obtain space for newNode
2) assign value to its data field
3) initialize ptr and preptr with head
4) traverse until preptr points to the node after which value is to be inserted, 
5) set the next field of preptr to newNode's address 
6) set next field of newNode to ptr 

*/
node *insertAfterNode(node *head)
{
    node *newNode, *ptr, *preptr;
    int num, val;
    printf("Enter the data :: ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted :: ");
    scanf("%d", &val);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;

    ptr = head;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    // printf("Here");
    preptr->next = newNode;
    newNode->next = ptr;
    return head;
}

node* insertBeforeNode(node* head)
{
    node *newNode, *ptr, *preptr;
    int num, val;
    printf("Enter the data :: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted :: ");
    scanf("%d", &val);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;

    ptr = head;
    preptr = ptr;
    while (ptr->data!=val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = newNode;
    newNode->next = ptr;
    return head;
}

node* insertAtEnd(node *head)
{
    node *ptr, *newNode;
    int num;
    printf("\nEnter the data :: ");
    scanf("%d", &num);

    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    newNode->next = NULL;

    ptr = head;
    while(ptr->next!=NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    return head;
}