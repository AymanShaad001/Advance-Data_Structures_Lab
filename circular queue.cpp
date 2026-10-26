#include <stdio.h>
#define MAX 10

int a[MAX];
int f = -1, r = -1;

void enque(int x) {
    if ((r + 1) % MAX == f) {
        printf("Queue overflow.\n");
    } else {
        if (r == -1 && f == -1) {
            f = 0;
            r = 0;
        } else {
            r = (r + 1) % MAX;
        }
        a[r] = x;
    }
}

void deque() {
    if (f == -1) {
        printf("Queue underflow.\n");
    } else {
        printf("Deleted element is %d\n", a[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % MAX;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue underflow.\n");
    } else {
        printf("Queue elements are: ");
        int i = f;
        while (1) {
            printf("%d ", a[i]);
            if (i == r)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enque(value);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}
