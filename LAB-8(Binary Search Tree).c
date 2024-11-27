#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node*Node=(struct Node*)malloc(sizeof(struct Node));
    Node->data=data;
    Node->left=Node->right=NULL;
    return Node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void display (struct Node*root){
    printf("The Tree Elements are:");
    inorder(root);
    printf("\n");
}


int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("1. Insert\n2. Display\n3. Pre-order\n4. Post-order\n5. In-order\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                display(root);
                break;
            case 3:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
