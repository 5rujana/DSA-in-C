#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a disk onto the linked list
void push(struct Node** head, int disk) {
    struct Node* newNode = createNode(disk);
    newNode->next = *head;
    *head = newNode;
}

// Function to pop a disk from the linked list
int pop(struct Node** head) {
    if (*head == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    int disk = temp->data;
    free(temp);
    return disk;
}

// Function to perform the Towers of Hanoi algorithm
void towersOfHanoi(int numDisks, struct Node** source, struct Node** aux, struct Node** dest) {
    if (numDisks == 0) {
        return;
    }

    towersOfHanoi(numDisks - 1, source, dest, aux);
    
    int disk = pop(source);
    push(dest, disk);
    printf("Move disk %d\n", disk);

    towersOfHanoi(numDisks - 1, aux, source, dest);
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    struct Node* source = NULL;
    struct Node* aux = NULL;
    struct Node* dest = NULL;

    // Push disks onto the source linked list in decreasing order of size
    for (int i = numDisks; i >= 1; i--) {
        push(&source, i);
    }

    printf("Tower of Hanoi solution:\n");
    towersOfHanoi(numDisks, &source, &aux, &dest);

    return 0;
}
