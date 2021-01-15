#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
    struct node *prev;
} node;

node *createDLL(node *head);
node *displayDLL(node *head);

node *insertAtBeg(node *head);
node *insertAfterNode(node *head);
node *insertBeforeNode(node *head);
node *insertAtEnd(node *head);

node *deleteAtBeg(node *head);
node *deleteAtEnd(node *head);
node *deleteBefore(node *head);
node *deleteAfter(node *head);
node *deleteList(node *head);

int main()
{
    node *head = NULL;
    int op;
    while (1)
    {
        printf("\n1. Create DLL \n2. Display \n3. Add node at beg \n4. Add node at end \n5. Add before a given node \n6. Add after a given node \n7. Delete a node from beg \n8. Delete node from end \n9. Delete a node before a given node \n10. Delete a node after a given node \n11. Delete entire list \n12. Exit\n");

        printf("Enter your option :: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            head = createDLL(head);
            break;
        case 2:
            head = displayDLL(head);
            break;
        case 3:
            head = insertAtBeg(head);
            break;
        case 4:
            head = insertAtEnd(head);
            break;
        case 5:
            head = insertBeforeNode(head);
            break;
        case 6:
            head = insertAfterNode(head);
            break;
        case 7:
            head = deleteAtBeg(head);
            break;
        case 8:
            head = deleteAtEnd(head);
            break;
        case 9:
            head = deleteBefore(head);
            break;
        case 10:
            head = deleteAfter(head);
            break;
        case 11:
            head = deleteList(head);
            break;
        case 12:
            exit(0);
        }
    }
    return 0;
}

node *createDLL(node *head)
{
    node *newNode;
    node *ptr;

    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");

    scanf("%d", &num);
    while (num != -1)
    {
        if (head == NULL)
        {
            newNode = (node *)malloc(sizeof(node));
            newNode->prev = NULL;
            newNode->data = num;
            newNode->next = NULL;
            head = newNode; // making newNode head of linkedlist
        }
        else
        {
            newNode = (node *)malloc(sizeof(node));
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;

            newNode->data = num;
            ptr->next = newNode;
            newNode->prev = ptr; // extra
            newNode->next = NULL;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return head; // add of head
}

node *displayDLL(node *head)
{
    node *ptr;
    ptr = head;
    // while(ptr->next != NULL)
    while (ptr != NULL)
    {
        printf("%d <===> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    // printf("%d <===> NULL", ptr->data);

    return head;
}

/*

1) obtain the space for node and allocate data in data field
2) head->prev(oldnode's prev) will now store newNode's address
3) and now newNode->next should also point to head (i.e head has old FirstNode's address)
4) we have newNode as first node, we need to now set the newly created firstNode's prev address as NULL
5) and finally make the head ptr point to newly created firstNode
*/

// done
node *insertAtBeg(node *head)
{
    node *newNode;
    int num;
    printf("Enter data: "); // <---
    scanf("%d", &num);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;

    head->prev = newNode; // could be head->next
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    return head;
}

// done
node *insertAtEnd(node *head)
{
    node *ptr, *newNode;
    int num;
    printf("\nEnter the data :: ");
    scanf("%d", &num);

    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = NULL;
    return head;
}

node* insertBeforeNode(node* head)
{
    node *newNode, *ptr;
    int num, val;
    printf("Enter the value before which data has to be inserted :: ");
    scanf("%d", &val);
    printf("enter data :: ");
    scanf("%d", &num);
    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
    return head;
}

node* insertAfterNode(node *head)
{
    node *newNode, *ptr;
    int num, val;
    printf("Enter the value after which data has to be inserted :: ");
    scanf("%d", &val);
    printf("\nEnter the data :: ");
    scanf("%d", &num);

    newNode = (node *)malloc(sizeof(node));
    newNode->data = num;
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
    newNode->prev = ptr;
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    return head;
}

// done
node *deleteAtBeg(node *head)
{
    node *ptr;
    ptr = head;
    if(head != NULL)
    {
        if (ptr->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
            free(ptr);
        }
        else
        {
            head = NULL;
            printf("List is now empty, just like your brain 😏");
        }
    }
    else
        printf("List is empty, deletion not possible ");
    return head;
}
node *deleteAtEnd(node *head)
{
    node *ptr;
    ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    free(ptr);
    return head;
}

node *deleteBefore(node* head)
{
    node *ptr, *temp;
    int val;
    printf("Enter the value before which the node has to be deleted :: ");
    scanf("%d", &val);
    ptr = head;
    while(ptr->data !=  val)
        ptr = ptr->next;

    temp = ptr->prev;
    if(temp ==  head)
        head = deleteAtBeg(head);
    else 
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr;
        free(temp);     // reema made a blunder here
    }
    return head;
}

// does not work if you give input as second last node 
node *deleteAfter(node* head)
{
    node *ptr, *temp;
    int val;
    printf("\nEnter value after which node has to be deleted :: ");
    scanf("%d", &val);
    ptr = head;
    while(ptr->data != val)
        ptr = ptr->next;
    temp = ptr->next;
    if (temp->next == NULL)
    {
        ptr->next = NULL;
        free(temp);
    }
    else
    {
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
    }
    return head;
}

node *deleteList(node *head)
{
    
    while (head != NULL)
    {
        printf("\n%d is to be deleted next !! ", head->data);
        head = deleteAtBeg(head);
    }
    return head;
}