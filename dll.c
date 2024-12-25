#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int ssn;
    char name[50];
    char department[50];
    char designation[50];
    float salary;
    long phone;
};

typedef struct Node {
    struct Employee data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(struct Employee value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, struct Employee value)
{
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(Node** head, struct Employee value)
{
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteAtBeginning(Node** head)
{
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(Node** head)
{
    if (*head == NULL) {
        return;
    }

    Node* current = *head;
    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    free(current);
}

void printList(Node* head)
{
    Node* current = head;
    int count = 1;

    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    printf("\n –––– Employee List ––––\n");

    while (current != NULL) {
        printf("\nEmployee %d:", count);
        printf("\n-----------------------");
        printf("\nSSN         : %d", current->data.ssn);
        printf("\nName        : %s", current->data.name);
        printf("\nDepartment  : %s", current->data.department);
        printf("\nDesignation : %s", current->data.designation);
        printf("\nSalary      : %.2f", current->data.salary);
        printf("\nPhone       : %ld", current->data.phone);
        printf("\n");

        current = current->next;
        count++;
    }

    printf("\n––––– End of List –––––\n");
}

int main()
{
    Node* head = NULL;
    struct Employee temp;
    int choice;

    while (1) {
        printf("\n1. Add employee at beginning");
        printf("\n2. Add employee at end");
        printf("\n3. Delete employee from beginning");
        printf("\n4. Delete employee from end");
        printf("\n5. Display all employees");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
                printf("\nEnter Employee details:");
                printf("\nSSN: ");
                scanf("%d", &temp.ssn);
                printf("Name: ");
                scanf(" %[^\n]s", temp.name);
                printf("Department: ");
                scanf(" %[^\n]s", temp.department);
                printf("Designation: ");
                scanf(" %[^\n]s", temp.designation);
                printf("Salary: ");
                scanf("%f", &temp.salary);
                printf("Phone: ");
                scanf("%ld", &temp.phone);

                if (choice == 1)
                    insertAtBeginning(&head, temp);
                else
                    insertAtEnd(&head, temp);
                printf("\nEmployee added successfully!\n");
                break;

            case 3:
            case 4:
                if (head == NULL) {
                    printf("\nList is empty - nothing to delete\n");
                    break;
                }
                if (choice == 3)
                    deleteAtBeginning(&head);
                else
                    deleteAtEnd(&head);
                printf("\nEmployee deleted from %s\n", (choice == 3) ? "beginning" : "end");
                break;

            case 5:
                system("clear");
                printList(head);
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                system("clear");
                break;

            case 6:
                printf("\nExiting program\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
