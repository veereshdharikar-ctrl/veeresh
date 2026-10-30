#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

void create(void)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }

    printf("Node created successfully!\n");
}
void insertionbeg()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next =head;
    head=newnode;
    if(temp==NULL)
    {
        temp=newnode;
    }
    printf(" Element inserted beging succesfull!\n");

}
void insertend()
{
   struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->next = NULL;

    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
        printf("Element inserted at end sucessfully!\n");
    }

}
void insertpos()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    
    int pos;
    int i=1;

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        temp=newnode;
    }
    else
    {
        printf("\nEnter the postion to insert element: ");
        scanf("%d",&pos);
        while(i<pos-1&&temp!=NULL)
        {
           temp=temp->next;
           i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        printf("Element inserted at the postion succesfuly!");
    }
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main(void)
{
    int n;

    do
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Create node\n");
        printf("2.insertion at beging\n");
        printf("3.insert at the end\n");
        printf("4.insertion at the position\n");
        printf("5.Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                create();
                break;
            case 2:
                insertionbeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                insertpos();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (n != 6);

    return 0;
}