
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

 struct node
 {
   int data;
   struct node *next;
 };

 struct node *temp;
 int item;

void beginsert (struct node **head){
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   scanf("%d",&item);
   new_node->data=item;
   new_node->next=*head;
   *head = new_node;
}

void endinsert(int count, struct node **head){
    int item;
    for (int i = 0; i < count; i++) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &item);
        new_node->data = item;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            temp = (*head);
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }


    
} 
   
void insertAtk( struct node **head){
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   printf("enter kth position\n");
   int k;
   scanf("%d",&k);
   printf("enter element\n");
   scanf("%d",&item);//item is universal element
   new_node->data=item;
   new_node->next=NULL;
   
   temp=*head;

   int pos=1;
   
   while (pos<k-1&&temp!=NULL)
   {
      temp=temp->next;
      pos++;
   }
   new_node->next=temp->next;
   temp->next=new_node;

}

void begindelete(struct node **head){
   
   if (*head==NULL)
   {
      printf("linked list is empty\n");
   }

   else if ((*head)->next==NULL)
   {
      free(*head);
      *head=NULL;
   } else
   {
      temp=*head;
      (*head)=(*head)->next;
      free(temp);
      temp=NULL;

   } 
}

void end_delete(struct node **head){
   
   if (*head==NULL)
   {
      printf("linked list is empty\n");
   }

   else if ((*head)->next==NULL)
   {
      free(*head);
      *head=NULL;
   } else
   {
      while (temp->next->next!=NULL)
      {
         temp=temp->next;
      }
      
   } 
   free(temp->next);
   temp->next=NULL;
}
  
  void deleteatK(struct node**head){
   
   if (*head==NULL)
   {
      printf("linked list is empty\n");
   }

   else if ((*head)->next==NULL)
   {
      free(*head);
      *head=NULL;
   } else
   {
   int pos=1;
   printf("enter kth position\n");
   int k;
   scanf("%d",&k);
   temp=*head;
   
    while (pos<k-1&& temp->next!=NULL)
      {
         temp=temp->next;
         pos++;
      }
      struct node* temp1=temp->next;
      temp->next=temp->next->next;
          
         free(temp1);
         temp1=NULL;
      

   } 
}
  
void display(struct node **head ){
   struct node *temp;
   temp=*head;
   if (temp==NULL)
   {
      printf("nothing to print");

   }else{
      while (temp!=NULL)
      {
         printf("\n%d\n",temp->data); 
         temp=temp->next;
      }
      
   }
   
}

 void lengthOfLL(struct node **head){
   struct node *temp;
   int count=0;
   temp=*head;
   if (temp==NULL)
   {
      printf("no of elements in linked list = 0");

   }else{
      while (temp!=NULL)
      { 
         temp=temp->next;
         count++;
      }
      printf("no of elements present in linked list = %d\n", count);
      
   }
      
   }


 int main(){
    struct node *head=NULL;
   printf("n of elemets in linked list\n");
   int count;
   scanf("%d",&count);
   printf("enter elements in linked list\n");
   // for (size_t i = 0; i < count; i++)
   // {
   //    beginsert(&head);
   // }
   // display(&head);
   
     
   endinsert(count, &head);
        display(&head);
        deleteatK(&head);
        display(&head);
      begindelete(&head);
      lengthOfLL(&head);
      display(&head);

   insertAtk(&head);
   display(&head);
   return 0;
        
   


 }
 

