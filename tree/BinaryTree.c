#include<stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* createLeftNode(struct Node* root,int value) {
    if (root == NULL) return;
    root->left=createNode(value);
    return root->left;
}

struct Node* createRightNode(struct Node* root,int value) {
    if (root == NULL) return;
    root->right=createNode(value);
    return root->right;
}
void freeTree(struct Node* root){
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main(){
    struct Node* node = createNode(12);
    printf("%d", node->value);
    freeTree(node);
    return 0;
}