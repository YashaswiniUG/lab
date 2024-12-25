#include <stdio.h>
#include <stdlib.h>

struct Student {
    char usn[20];
    char name[50];
    char branch[20];
    int semester;
    char phone[15];
};

struct Node {
    struct Student data;
    struct Node* next;
};

struct Node* createNode(struct Student value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, struct Student value)
{
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, struct Student value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtBeginning(struct Node** head)
{
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteAtEnd(struct Node** head)
{
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;

    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void printList(struct Node* head)
{
    struct Node* current = head;
    int count = 1;

    if (head == NULL) {
        printf("\nList is empty!");
        return;
    }

    printf("\n –––– Student List ––––\n");

    while (current != NULL) {
        printf("\nStudent %d:", count);
        printf("\n-----------------------");
        printf("\nUSN      : %s", current->data.usn);
        printf("\nName     : %s", current->data.name);
        printf("\nBranch   : %s", current->data.branch);
        printf("\nSemester : %d", current->data.semester);
        printf("\nPhone    : %s", current->data.phone);
        printf("\n");

        current = current->next;
        count++;
    }

    printf("\n––––– End of List –––––\n");
}

int main()
{
    struct Node* head = NULL;
    struct Student student;
    int choice;
    while (1) {
        printf("\n1. Insert student at beginning");
        printf("\n2. Insert student at end");
        printf("\n3. Delete student at beginning");
        printf("\n4. Delete student at end");
        printf("\n5. Display all students");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            case 2:
                printf("\nEnter student details:");
                printf("\nUSN: ");
                scanf("%s", student.usn);
                printf("Name: ");
                scanf(" %[^\n]s", student.name);
                printf("Branch: ");
                scanf("%s", student.branch);
                printf("Semester: ");
                scanf("%d", &student.semester);
                printf("Phone: ");
                scanf("%s", student.phone);
                if (choice == 1)
                    insertAtBeginning(&head, student);
                else
                    insertAtEnd(&head, student);
                break;

            case 3:
            case 4:
                if (head == NULL) {
                    printf("\nList is empty - nothing to delete\n");
                    break;
                }

                if (choice == 3) {
                    deleteAtBeginning(&head);
                    printf("\nDeleted student from beginning\n");
                } else {
                    deleteAtEnd(&head);
                    printf("\nDeleted student from end\n");
                }
                break;

            case 5:
                system("clear");
                printf("\nStudent List:\n");
                printList(head);
                printf("\n\nPress Enter to continue...");
                getchar();
                getchar();
                system("clear");
                break;

            case 6:
                printf("\nExiting program\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}