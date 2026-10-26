#include <stdio.h>
#define MAX 10

int a[MAX], f = -1, r = -1;

void insrear(int x) {
    if ((f == 0 && r == MAX - 1) || (f == r + 1)) {
        printf("Queue overflow.\n");
    } else {
        if (f == -1) {
            r = 0;
            f = 0;
        } else if (r == MAX - 1) {
            r = 0;
        } else {
            r++;
        }
        a[r] = x;
    }
}

void insfront(int x) {
    if ((f == 0 && r == MAX - 1) || (f == r + 1)) {
        printf("Queue overflow.\n");
    } else {
        if (f == -1) {
            f = 0;
            r = 0;
        } else if (f == 0) {
            f = MAX - 1;
        } else {
            f--;
        }
        a[f] = x;
    }
}

void delrear() {
    if (f == -1) {
        printf("Queue underflow.\n");
    } else {
        printf("Deleted Element is %d\n", a[r]);
        if (f == r) {
            f = -1;
            r = -1;
        } else if (r == 0) {
            r = MAX - 1;
        } else {
            r--;
        }
    }
}

void delfront() {
    if (f == -1) {
        printf("Queue underflow.\n");
    } else {
        printf("Deleted element is %d\n", a[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else if (f == MAX - 1) {
            f = 0;
        } else {
            f++;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue underflow.\n");
        return;
    }
    int i = f;
    while (i != r) {
        printf("%d -> ", a[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", a[i]);
}

int main() {
    int choice, value;
    
    do {

        printf("1. Insert Rear\n");
        printf("2. Insert Front\n");
        printf("3. Delete Rear\n");
        printf("4. Delete Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insrear(value);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insfront(value);
                break;
            case 3:
                delrear();
                break;
            case 4:
                delfront();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
