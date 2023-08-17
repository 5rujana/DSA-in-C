#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isQueueEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

int isQueueFull() {
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    if (isQueueFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isQueueEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeued = queue[front];
    if (front == rear) {
        // Reset queue
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return dequeued;
}

void printQueue() {
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Printing queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Simulating a queue of integers
    enqueue(1);
    enqueue(2);
    enqueue(3);
    
    printQueue(); // Output: Printing queue: 1 2 3
    
    int dequeued = dequeue();
    printf("Dequeued item: %d\n", dequeued); // Output: Dequeued item: 1
    
    printQueue(); // Output: Printing queue: 2 3
    
    return 0;
}
