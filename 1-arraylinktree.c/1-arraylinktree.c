#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void GenerateArrayTree(int* tree) {
	int list[] = { 1, 2, 9, 3, 5, 10, 13, 4, 6, 7, 8, 11, 12, 14, 15 };

	for (int i = 0; i < 15; i++) {
		tree[i] = list[i];
	}

	for (int i = 0; i < 15; i++) {
		printf("%d ", tree[i]);
	}
	printf("\n\n");

}

void ArrayPreOrder(int* tree, int index, int size) {
    if (index >= size) return;

    printf("%d ", tree[index]);
    ArrayPreOrder(tree, 2 * index + 1, size);
    ArrayPreOrder(tree, 2 * index + 2, size);
}

void ArrayInOrder(int* tree, int index, int size) {
    if (index >= size) return;

    ArrayInOrder(tree, 2 * index + 1, size);
    printf("%d ", tree[index]);
    ArrayInOrder(tree, 2 * index + 2, size);
}

void ArrayPostOrder(int* tree, int index, int size) {
    if (index >= size) return;

    ArrayPostOrder(tree, 2 * index + 1, size);
    ArrayPostOrder(tree, 2 * index + 2, size);
    printf("%d ", tree[index]);

}

void ArrayOrders(int* tree) {
    int size = 15; 

    ArrayPreOrder(tree, 0, size);
    printf("\n");

    ArrayInOrder(tree, 0, size);
    printf("\n");

    ArrayPostOrder(tree, 0, size);
    printf("\n");
}


void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}


void GenerateLinkTree(TreeNode* root) {
   
    PlaceNode(root, 0, 2);   
    PlaceNode(root, 1, 9);   

    PlaceNode(root->left, 0, 3);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->left->left, 0, 4);
    PlaceNode(root->left->right, 0, 6);
    PlaceNode(root->left->right, 1, 7);

    PlaceNode(root->right, 0, 10);
    PlaceNode(root->right, 1, 13);
    PlaceNode(root->right->left, 0, 11);
    PlaceNode(root->right->left, 1, 12);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}


void LinkPreOrder(TreeNode* node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    LinkPreOrder(node->left);
    LinkPreOrder(node->right);
}


void LinkInOrder(TreeNode* node) {
    if (node == NULL) return;

    LinkInOrder(node->left);
    printf("%d ", node->data);
    LinkInOrder(node->right);
}


void LinkPostOrder(TreeNode* node) {
    if (node == NULL) return;

    LinkPostOrder(node->left);
    LinkPostOrder(node->right);
    printf("%d ", node->data);
}


void LinkOrders(TreeNode* root) {
    
    LinkPreOrder(root);
    printf("\n");

    LinkInOrder(root);
    printf("\n");

    LinkPostOrder(root);
    printf("\n");
}

int main() {
    int arr[15];
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    
    GenerateArrayTree(arr);
    ArrayOrders(arr);
    printf("\n");
    
    GenerateLinkTree(root); 
    LinkOrders(root);
    printf("\n");

    return 0;
}