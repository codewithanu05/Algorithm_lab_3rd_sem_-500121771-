#include <stdio.h> 
#include <stdlib.h> 
struct Node { 
    int data; 
    struct Node* left; 
    struct Node* right; }; 
struct Node* createNode(int value) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    if (newNode == NULL) { 
        printf("Memory allocation failed\n"); } 
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 
void inorder(struct Node* root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); } 
} 
struct Node* insertRecursive(struct Node* root, int value) { 
    if (root == NULL) { 
        return createNode(value); } 
    if (value < root->data) { 
        root->left = insertRecursive(root->left, value); 
    } else if (value > root->data) { 
        root->right = insertRecursive(root->right, value); } 
    return root; 
}
struct Node* insertIterative(struct Node* root, int value)
{
     struct Node* newNode = createNode(value);

    if (root == NULL) {
        return newNode;
    }

    struct Node* parent = NULL;
    struct Node* current = root;

    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            free(newNode);
            return root;
        }
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
};
 
int main(){
     struct Node* root = NULL; 
    int choice, value,n; 
    printf("Enter the number of values you want to insert: "); 
    scanf("%d",&n); 
    for(int i=0; i<n;i++){ 
    printf("Enter value%d: ",i+1); 
    scanf("%d", &value); 
    printf("Enter your choice:\n 1) Insert Recursively\n 2) Insert Iteratively");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        root = insertRecursive(root, value); 
        break;
    case 2:
        root = insertIterative(root, value); 
    break;    
    
    default:
        break;
    }
    } 
    inorder(root); 
    printf("\n"); 
}
