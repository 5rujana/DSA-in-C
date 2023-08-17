#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node * prev;
   struct node *next;
};

   void begininsert(struct node **head, struct node **tail, int item){
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->prev=NULL;
   newnode->next=NULL;
   newnode->data=item;
   if (*head==*tail==NULL)
   {
      *head=*tail=newnode;
   }else
   {
      (*head)->prev=newnode;
      newnode->next= *head;
      *head=newnode;
   }
   }

   void endinsert(struct node **head , int item, struct node **tail){
      
         struct node *newnode=(struct node*)malloc(sizeof(struct node));
         
         newnode->prev=NULL;
         newnode->next=NULL;
         newnode->data=item;
         if (*head==*tail==NULL)
         {
            *head=*tail=newnode;
         }else
         {
            (*tail)->next=newnode;
            newnode->prev= (*tail);
            *tail=newnode;
         }
         
         
   }


   void insertatk( struct node **head, struct node **tail, int item){
      struct node *newnode=(struct node*)malloc(sizeof(struct node));
      newnode->prev=NULL;
      newnode->next=NULL;
      newnode->data=item;
      struct node *temp;
      int pos=0;
      int k;
      printf(" enter the position\n");
      scanf("%d",&k);
      if (k==1){
         newnode->next=*head;
         (*head)->prev=newnode;
         *head=newnode;
      }else{
      while(pos<=k-2&&temp->next!=NULL){
         temp=temp->next;
         pos++;
      }
      newnode->prev=temp;
      newnode->next=temp->next;
      temp->next=newnode;
      newnode->next->prev=newnode;}
      
   }

   void deleteatbegin( struct node **head, struct node **tail){
      if (*head==*tail==NULL)
      {
         printf("no elements are present in LL");
      }else if(*head==*tail){
         free(*head);
         *head=*tail=NULL;
      }else {
         struct node *temp;
         temp=*head;
         *head=(*head)->next;
         (*head)->prev=NULL;
         free(temp);

      }
   }

   void deleteatend( struct node **head, struct node **tail){
      struct node *temp;
      if (*head==*tail==NULL)
      {
         printf("no elements are present in LL");
         return;
      }else if((*head)== *tail){
         free(head);
         *head=*tail=NULL;
      }else {
         temp=*tail;
         *tail=(*tail)->prev;
         (*tail)->next=NULL;
         free(temp);
      }

   }

   // void deleteatk(struct node **head){
   //    // temp->prev->next=temp->next;
   //    //temp->next->prev=temp->prev;
   //    // free(temp);
      
   // }


   void display(struct node **head){
      struct node*temp;
      temp=(*head);
      if (temp==NULL)
      {
         printf("nothing to print");
      }else{
      
      while(temp!=NULL){
         printf("\n%d\n",temp->data);
         temp=temp->next;
      }}
   }



int main(){
   struct node* head=NULL;
   struct node* tail=NULL;
   printf("elements to be added in linked list linked list");int item;
   scanf("%d", &item);
   
   
     

   return 0;

}