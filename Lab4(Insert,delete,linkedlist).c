#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertatBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertatEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* insertatPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position doesn't exist\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. No element has been deleted\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. No element will be deleted\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    free(current);
    previous->next = NULL;
    return head;
}

struct Node* deleteSpecificElement(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element is not present in the list\n");
        return head;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

void displaylist(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at First\n");
        printf("2. Insert element at End\n");
        printf("3. Insert element at Position\n");
        printf("4. Delete First Element\n");
        printf("5. Delete Last Element\n");
        printf("6. Delete Specified Element\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                head = insertatBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertatEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertatPosition(head, data, position);
                break;
            case 4:
                head = deleteFirst(head);
                break;
            case 5:
                head = deleteLast(head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                head = deleteSpecificElement(head, data);
                break;
            case 7:
                printf("Linked List: ");
                displaylist(head);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
