#include<stdio.h>
#define SIZE 100
int queue[SIZE],head=-1,tail=-1;
int queueEmpty()
{
    if(head==-1) return 1;
    else return 0;
}
int queueFull()
{
    if(tail==SIZE-1) return 1;
    else return 0;
}
void queueOverflowError()
{
    printf("\nError : Queue Overflow");
}
void queueUnderflowError()
{
    printf("\nError : Queue underflow");
}
void enqueue(int data)
{
    if(queueFull()) queueOverflowError();
    else if(queueEmpty())
    {
        head=0;
        tail=0;
        queue[tail]=data;
    }
    else  queue[++tail]=data;
}
void dequeue()
{
    if(queueEmpty()) queueUnderflowError();
    else if(head==tail)
    {
        printf("\nDequeued : %d",queue[head]);
        head=-1;
        tail=-1;
    }
    else
    {
        int del = queue[head++];
        printf("\nDequeued : %d",del);
    }
}
void display()
{
    if(queueEmpty()) queueUnderflowError();
    else
    {
        printf("\n");
        for(int i=head;i<=tail;i++) printf("%d ",queue[i]);
    }
}
void main()
{
    int choice,data;
    do
    {
        printf("\nChoose an operation :");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter an option : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to enqueue :");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
        }
    }
    while(choice<=3);
}
