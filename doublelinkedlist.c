#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *temp = NULL;


void create(void)
{
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev= NULL;

    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }

    printf("Node created successfully!\n");

}

void insertbeg(void)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter the new element to insert at beginning: ");
    if (scanf("%d", &newnode->data) != 1)
    {
        printf("Invalid input! Please enter an integer.\n");
        free(newnode);
        return;
    }

    newnode->next = head;
    newnode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newnode;
    }
    
    head = newnode;

    if (temp == NULL)
    {
        temp = newnode;
    }

    printf("Inserted successfully!\n");
}

void deletebeg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linked list empty!\n");
        return;
    }
    if(head->next==NULL)
    {
       printf("deleted element: %d",head->data);
       free(head);
       head=NULL;
       return; 
    }
    else
    {
        temp=head;
        head=temp->next;
        head->prev=NULL;
        printf("Deleted element is: %d ",temp->data);
        free(temp);
    }
}
void deleteEnd()
{
    struct node *temp;
    struct node *current;
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    if(head->next==NULL)
    {
       printf("deleted element: %d",head->data);
       free(head);
       head=NULL;
       return; 
    }
    temp=head;
    current=head;
    while(current->next!=NULL)
    {
        temp=current;
        current=current->next;
    }
    temp->next=NULL;
    printf("Deleted element is: %d ",current->data);
    free(current);
    
}
void display(void)
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
        printf("2.insert at beging\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                create();
                break;
            
            case 2:
                 insertbeg();
                 break;
            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (n!=4);

    return 0;
}