#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int queue[MAX], front = -1, rear = -1;


void insert();
int delete();
void display();

void insert() {
    if (front==(rear + 1) % MAX ) {  
        printf("Circular Queue is Full\n");
        return;
    }
    if (front == -1,rear==-1) {  
        front = 0;
        rear=0;
    }
    else{
    rear = (rear + 1) % MAX;
    }  

    printf("Enter the element to be inserted: ");
    scanf("%d", &queue[rear]);  
}

int delete() {
    if (front == -1&&rear==-1) {  
        printf("Circular Queue is empty\n");
        return -1;
    }
    int item = queue[front]; 
    if (front == rear) {  
        front = -1;
        rear = -1;
    } else 
    {
        front = (front + 1) % MAX;  
    }
    return item;  
}

void display() {
    if (front == -1&&rear==-1) {  
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]); 
        }
    } else 
    {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);  
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);  
        }
    }
    printf("\n");  
}

int main() {
    int choice;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                printf("Deleted item: %d\n", delete());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
