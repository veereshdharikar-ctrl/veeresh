#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp=NULL;

void create()
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
        
        temp->next=newnode;
        temp=newnode;
    }
    printf("Element inserted at end sucessfully!\n");

}
void insertpos()
{
    struct node *newnode,*current;

    newnode = (struct node *)malloc(sizeof(struct node));

    int pos,i=1;
    printf("\nEnter the postion to insert element: ");
    scanf("%d",&pos);
    
    if(pos<1)
    {
        printf("invalid postion!");
    }

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the new node data: ");
    scanf("%d", &newnode->data);
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
        if(temp==NULL)
         temp=newnode;
        return;

    }
    current=head;
    while(i<pos-1&& current!=NULL)
    {
        current=current->next;
        i++;
    }
    if(current==NULL)
    {
        printf("invalid position!\n");
        free(newnode);
        return;
    }
   
    newnode->next=current->next;
    current->next=newnode;
    if(newnode->next==NULL)
    temp=newnode;
    printf("Element inserted at the postion succesfuly!");
    
}

void deleteatbeg()
{
   struct node *item=head;
   if(head==NULL)
   {
        printf("linked is under flow !");
        return;
   } 
   else
   {
        printf("%d ",item->data);
        head=item->next;
        free(item);
        if(head==NULL)
        temp=NULL;
   }

}
void deleteatend()
{
   struct node *current;
   struct node *item;
   if(head==NULL)
   {
    printf("linked list is empty!");
   }
   current=head; 
   if(head->next==NULL)
   {
    printf("%d ",head->data);
    free(head);
    head=NULL;
    return;
   }
   else
   {
    while(current->next->next!=NULL)
    {
        current=current->next;
    }
    item=current->next;
    printf("%d ",item->data);
    free(item);
    current->next =NULL;
    temp=current;
   }

}
int count()
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
void deletepos()
{
    struct node *current;
    struct node *prev;
    int size=count();
    int pos,i=1;
    if (head==NULL)
    {
        printf("linked list is empty!");
        return;
    }
    printf("\nEnter the postion to delete element: ");
    scanf("%d",&pos);
    
    if(pos<1||pos>size)
    {
        printf("invalid postion !");
        return;
    }
    
    current=head;
    if(pos==1)
    {
        printf("%d ",head->data);
        current=head;
        head=head->next;
        free(current);
        return;
    }
    while(i!=pos)
    {
        prev=current;
        current=current->next;
        i++;
    }
    prev->next=current->next;
    printf("Deleted element at pos %d ",current->data);
    free(current);
    
    
    
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

    while (temp!= NULL)
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
        printf("1.Create node\n");
        printf("2.Insertion at beging\n");
        printf("3.Insert at the end\n");
        printf("4.Insertion at the position\n");
        printf("5.Delete at beging\n");
        printf("6.Delete at the end\n");
        printf("7.Deleting element at the pos\n");
        printf("8.Display the elements \n");
        printf("9.Exit\n");
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
                deleteatbeg();
                break;
            case 6:
                deleteatend();
                break;
            case 7:
                deletepos();
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

    } while (n != 9);

    return 0;
}