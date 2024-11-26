#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int key;
} element;

element Queue[MAX_SIZE];
int front = -1;
int rear = -1;
int count = 0;

int Qfull() {
    return count == MAX_SIZE;
}

int Qempty() {
    return count == 0;
}

void insert(int ele) {
    rear = (rear + 1) % MAX_SIZE;
    if (front == -1)
        front = 0;
    count++;
    Queue[rear].key = ele;
}

int deleteq() {
    int ret;
    ret = Queue[front].key;
    front = (front + 1) % MAX_SIZE;
    count--;
    return ret;
}

void display() {
    int i, j;
    if (Qempty())
        printf("\nQueue is empty.\n");
    else {
        j = front;
        printf("\nElements in the Queue are:\n");
        for (i = 0; i < count; i++) {
            printf("%d(%d)\t", Queue[j].key, j);
            j = (j + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int n = 4, i, ch, ele, flag = 1;

    while (flag) {
        printf("\nMenu driven Program in C for the Circular QUEUE operations\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            if (Qfull()) {
                printf("\nQueue Full.\n");
            } else {
                printf("\nEnter the value for insert: ");
                scanf("%d", &ele);
                insert(ele);
            }
            break;

        case 2:
            if (!Qempty()) {
                ele = deleteq();
                printf("\n%d\n", ele);
            } else {
                printf("\nQueue Empty.\n");
            }
            break;

        case 3:
            display();
            break;

        default:
            flag = 0;
        }
    }
    return 0;
}
