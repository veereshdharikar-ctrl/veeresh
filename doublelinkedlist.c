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
void insertEnd(void)
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
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    printf("inserted elements successfully!");

}
int count(void)
{
    int i=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}
void insertPos(void)
{
    struct node *current,*newnode;
    int i=1,pos;

    printf("Enter the postion to enter the elemet:\n");
    if(scanf("%d",&pos)!=1)
    {
        printf("position is invalid enter vaild position!\n");
        return;
    }
    
    int size=count();
    
    if(pos<1||pos>size+1)
    {
        printf("psition is invaild\n");
        return;
    }
    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the new node data: ");
    if(scanf("%d", &newnode->data)!=1)
    {
        printf("invaid data!\n");
        free(newnode);
        return;
    }

    if(pos==1)
    {
        newnode->next = head;
        newnode->prev = NULL;
        
        if (head != NULL)
            head->prev = newnode;
    
        head = newnode;

        if (temp == NULL)
            temp = newnode;
    
    }
    else
    {
        current=head;
        while(i!=pos-1)
        {
            current=current->next;
            i++;
        }
        newnode->next=current->next;
        newnode->prev=current;

        if(current->next!=NULL)
            current->next->prev=newnode;

        current->next=newnode;

        if(newnode->next==NULL)
            temp=newnode;
    }
printf("Inserted successfully!");
}
void deletebeg()
{
    struct node *current;
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
       temp=NULL;
       return; 
    }
    current=head;
    printf("Deleted element is: %d ",current->data);
    head=head->next;
    if(head!=NULL)
        head->prev=NULL;
    else
        temp=NULL;    
    free(current);
    
}
void deleteEnd()
{
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
       temp=NULL;
       return; 
    }
    current=temp;
    temp=temp->prev;
    temp->next=NULL;
    printf("Deleted element is: %d ",current->data);
    free(current);
    
}
void DeletePos(void)
{
    int pos,i=1;
    int size=count();
    struct node *current,*pervious;
    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    printf("Enter the position to delete the element:\n");
    scanf("%d",&pos);
    if(pos<1||pos>size)
    {
        printf("Enter the valid postion !invalid position\n");
        return;
    }
    current=head;
    if(pos==1)
    {
        printf("Deleted element:%d ",current->data);
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        else
            temp=NULL;
        free(current);
        return;
    }
    while(i!=pos)
    {
        pervious=current;
        current=current->next;
        i++;
    }
    printf("Deleted element is: %d ",current->data);
    pervious->next=current->next;
    if(current->next!=NULL)
        current->next->prev=pervious;
    else
        temp=pervious;  
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
        printf("3.insert at end\n");
        printf("4.Insert at position\n");
        printf("5.Delete at beging\n");
        printf("6.Delete at end\n");
        printf("7.Delete at the postion\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
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
                insertEnd();
                break;
            case 4:
                insertPos();
                break;
            case 5:
                deletebeg();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                DeletePos();    
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (n!=9);

    return 0;
}