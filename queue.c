#include<stdio.h>
#define n 5     
int queue[n];
int front=-1;
int rear=-1;
void enque()
{
    int x;
    printf("Enter the data to be inserted in queue: \n");
    scanf("%d",&x);
    if(front==-1&& rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void deque()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%n;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        printf("%d",queue[front]);
    }
    else
    {
        printf("Queue elements are\n");
        i=front;
        while(1)
        {
            printf("%d  ",queue[i]);
            if(i==rear)
            break;
            i=(i+1)%n;
        }
        printf("\n");
    }

}
int main()
{
    int choice;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    } while (choice!=4);
    return 0;

}