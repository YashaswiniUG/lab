#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node *root)
{
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct node *search(struct node *root, int value)
{
    if (root == NULL || root->data == value) {
        if (root == NULL)
            printf("\nValue %d not found in the tree\n", value);
        else
            printf("\nValue %d found in the tree\n", value);
        return root;
    }

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

int main()
{
    struct node *root = NULL;
    int choice, value, n, i;

    while(1) {
        printf("\n1. Insert the values");
        printf("\n2. Inorder traversal");
        printf("\n3. Preorder traversal");
        printf("\n4. Postorder traversal");
        printf("\n5. Search a value");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of values to insert: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    printf("Enter value %d: ", i+1);
                    scanf("%d", &value);
                    if(root == NULL)
                        root = insert(root, value);
                    else
                        insert(root, value);
                }
                break;

            case 2:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
