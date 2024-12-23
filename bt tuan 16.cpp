#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;


Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; 
    return newNode;
}

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}


int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;

    
    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;
    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;

    return x; 
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;


    y->left = x;
    x->right = T2;

   
    x->height = (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right)) + 1;
    y->height = (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right)) + 1;

    return y; 
}


Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

 
    if (key < node->value)
        node->left = insert(node->left, key);
    else if (key > node->value)
        node->right = insert(node->right, key);
    else 
        return node;

    
    node->height = (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right)) + 1;

    
    int balance = getBalance(node);

    
    if (balance > 1 && key < node->left->value)
        return rightRotate(node);

    
    if (balance < -1 && key > node->right->value)
        return leftRotate(node);

    
    if (balance > 1 && key > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    
    if (balance < -1 && key < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}


void add(Node** root, int key) {
    *root = insert(*root, key);
}


int main() {
    Node* root = NULL;
    int values[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        add(&root, values[i]);
    }

    printf("Duyet cay AVL theo thu tu in-order: \n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
