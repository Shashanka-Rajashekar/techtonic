#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* bToDLL(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode* left_tail = bToDLL(root->left);
    if (left_tail == NULL) {
        left_tail = root;
    } else {
        left_tail->right = root;
        root->left = left_tail;
        left_tail = root;
    }
    struct TreeNode* right_tail = bToDLL(root->right);
    if (right_tail != NULL) {
        right_tail->left = left_tail;
        left_tail->right = right_tail;
    }
    while (left_tail->left != NULL) {
        left_tail = left_tail->left;
    }
    return left_tail;
}

int main() {
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = 10;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->val = 20;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->val = 40;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->val = 60;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->val = 30;
    root->right->left = NULL;
    root->right->right = NULL;

    struct TreeNode* head = bToDLL(root);

    printf("Inorder traversal of DLL (left to right):\n");
    struct TreeNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->right;
    }
    printf("\n");

    printf("Inorder traversal of DLL (right to left):\n");
    current = head;
    while (current->right != NULL) {
        current = current->right;
    }
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->left;
    }
    printf("\n");

    return 0;
}
