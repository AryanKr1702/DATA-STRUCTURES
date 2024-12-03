#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct TreeNode* insertBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val); 
    }

   
    if (val < root->val) {
        root->left = insertBST(root->left, val); 
    } else if (val > root->val) {
        root->right = insertBST(root->right, val); 
    }

    return root;
}


struct TreeNode* searchBST(struct TreeNode* root, int val) {
  
    if (root == NULL || root->val == val) {
        return root;
    }

  
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}


void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int searchValue;

    
    int values[] = {4, 2, 7, 1, 3};
    int n = sizeof(values) / sizeof(values[0]);


    for (int i = 0; i < n; i++) {
        root = insertBST(root, values[i]);
    }

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Enter the value to search for in the BST: ");
    scanf("%d", &searchValue);

    struct TreeNode* result = searchBST(root, searchValue);

    if (result != NULL) {
        printf("Subtree rooted at node with value %d (in-order): ", searchValue);
        inOrderTraversal(result);
        printf("\n");
    } else {
        printf("Node with value %d not found in the tree.\n", searchValue);
    }

    return 0;
}