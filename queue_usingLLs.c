#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void enqueue( struct node **front , struct node **rear, int item){ //insert at end 
    struct node *newnode= (struct node *)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    if (*front==NULL && *rear==NULL)
    {
        *front= *rear= newnode;
    }else{
        (*rear)->next=newnode;
        (*rear)=newnode;
    }
     
}

void dequeue(struct node **front, struct node **rear){ //delete at begin
    struct node *temp;
    if (*front == NULL && *rear == NULL)
    {
        printf("queue is empty\n");
    }else if (*front==*rear)
    {
        free(*front);
        *front=*rear=NULL;
    }else{
        temp= *front;
        *front=(*front)->next;
        free(temp);
    }
    
    
    
}

 void display( struct node **front , struct node **rear){
    struct node *temp= *front;
       
            while (temp!=NULL)
            {
                printf("\n%d\n",temp->data);
                temp=temp->next;
            }    
        
}

int main(){
    struct node *front=NULL;
    struct node *rear=NULL;
    enqueue(&front,&rear,1);
    enqueue(&front,&rear,2);
    enqueue(&front,&rear,3);
    enqueue(&front,&rear,4);
    enqueue(&front,&rear,5);
    display(&front,&rear);
    printf("\n\n");
    dequeue(&front,&rear);
    display(&front,&rear);

}       
    