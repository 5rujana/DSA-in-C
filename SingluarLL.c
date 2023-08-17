#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};

void insertAtBegin(struct node **head, struct node **tail, int item){
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = item;
   newNode->next = *head;

   if (*head == NULL) {
      *tail = newNode;
   }
   *head = newNode;
}

void insertAtEnd(struct node **head, struct node **tail, int item){
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = item;
   newNode->next = NULL;

   if (*head == NULL) {
      *head = newNode;
      *tail = newNode;
   } else {
      (*tail)->next = newNode;
      *tail = newNode;
   }
}

void insertAtPos(struct node **head, struct node **tail, int item){
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = item;
   newNode->next = NULL;

   struct node *temp = *head;
   int pos = 0;
   int k;
   printf("Enter the position: ");
   scanf("%d", &k);

   if (k == 1) {
      newNode->next = *head;
      *head = newNode;
   } else {
      while (pos <= k - 2 && temp->next != NULL) {
         temp = temp->next;
         pos++;
      }
      newNode->next = temp->next;
      temp->next = newNode;
      if (newNode->next == NULL) {
         *tail = newNode;
      }
   }
}

void deleteAtBegin(struct node **head, struct node **tail){
   if (*head == NULL) {
      printf("No elements are present in the linked list.\n");
   } else {
      struct node *temp = *head;
      *head = (*head)->next;
      free(temp);
      if (*head == NULL) {
         *tail = NULL;
      }
   }
}

void deleteAtEnd(struct node **head, struct node **tail){
   if (*head == NULL) {
      printf("No elements are present in the linked list.\n");
   } else if (*head == *tail) {
      free(*head);
      *head = *tail = NULL;
   } else {
      struct node *temp = *head;
      while (temp->next != *tail) {
         temp = temp->next;
      }
      free(*tail);
      *tail = temp;
      (*tail)->next = NULL;
   }
}

void deleteAtPos(struct node **head, struct node **tail){
   if (*head == NULL) {
      printf("No elements are present in the linked list.\n");
   } else {
      struct node *temp = *head;
      int pos = 0;
      int k;
      printf("Enter the position to delete: ");
      scanf("%d", &k);

      if (k == 1) {
         *head = temp->next;
         free(temp);
         if (*head == NULL) {
            *tail = NULL;
         }
      } else {
         struct node *prev = NULL;
         while (pos < k - 1 && temp != NULL) {
            prev = temp;
            temp = temp->next;
            pos++;
         }
         if (temp == NULL) {
            printf("Invalid position.\n");
         } else {
            prev->next = temp->next;
            free(temp);
            if (prev->next == NULL) {
               *tail = prev;
            }
         }
      }
   }
}

void display(struct node *head){
   struct node *temp = head;
   if (temp == NULL) {
      printf("Linked list is empty.\n");
   } else {
      printf("Linked list elements:\n");
      while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
      }
      printf("\n");
   }
}

int main(){
   struct node* head = NULL;
   struct node* tail = NULL;
   int choice, item;
  printf("\n1. Insert at beginning");
      printf("\n2. Insert at end");
      printf("\n3. Insert at position");
      printf("\n4. Delete at beginning");
      printf("\n5. Delete at end");
      printf("\n6. Delete at position");
      printf("\n7. Display");
      printf("\n8. Exit");
      
   while (1) {
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            insertAtBegin(&head, &tail, item);
            break;
         case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            insertAtEnd(&head, &tail, item);
            break;
         case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            insertAtPos(&head, &tail, item);
            break;
         case 4:
            deleteAtBegin(&head, &tail);
            break;
         case 5:
            deleteAtEnd(&head, &tail);
            break;
         case 6:
            deleteAtPos(&head, &tail);
            break;
         case 7:
            display(head);
            break;
         case 8:
            exit(0);
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }

   return 0;
}
