#include<Stdio.h>

int n = 5;
int rear = -1;
int front =-1;
int arr[5];

void enqueue(int element){
    if ((rear+1)%n==front)
    {
        printf("queue is full\n");
    } else if (rear==front==-1)
    {
        rear=front=0;
        arr[rear]=element;
    }else
    {
        rear=(rear+1)%n;
        arr[rear]=element;
    } 
    
}

void dequeue(int element){
    if (rear==front==-1)
    {
        printf("queue is empty\n");
    }else if( front==rear){
        printf("%d", arr[front]);
        front=rear=-1;
    }else{
         printf("%d", arr[front]);
         front=(front+1)%n;
    }
    
}


void display(int element){
    if (rear==front==-1)
    {
         printf("queue is empty\n");
    }else
    {
        for (int i = front; i != rear; (i+1)%n)
        {
            printf("%d",arr[i]);
        }

        printf("%d", arr[rear] );
        
    }
    
    
}