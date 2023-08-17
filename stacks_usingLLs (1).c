#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node** head, struct node** tail, int item) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = item;
    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void pop(struct node** head, struct node** tail) {
    if (*head == NULL) {
        printf("stack is empty\n");
    } else if (*head == *tail) {
        free(*head);
        *head = NULL;
        *tail = NULL;
    } else {
        struct node* temp = *head;
        while (temp->next != *tail) {
            temp = temp->next;          // insert at the end and delete at the end eating my brain
        }
        free(*tail);
        *tail = temp;
        (*tail)->next = NULL;
    }
}

void display(struct node** head) {
    struct node* temp = *head;
    if (temp == NULL) {
        printf("stack is empty\n");
    }
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;
    struct node* tail = NULL;

    push(&head, &tail, 1);
    push(&head, &tail, 2);
    push(&head, &tail, 3);
    push(&head, &tail, 4);
    push(&head, &tail, 5);
    display(&head);
    pop(&head, &tail);
    printf("\n\n");
    display(&head);
}
