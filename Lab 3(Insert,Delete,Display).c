#include <stdio.h>
#define SIZE 5 

int queue[SIZE];
int front = -1, rear = -1;


int isFull() {
    return (front == (rear + 1) % SIZE);
}


int isEmpty() {
    return (front == -1);
}


void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        printf("Inserted %d\n", element);
    }
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % SIZE;
        }
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
