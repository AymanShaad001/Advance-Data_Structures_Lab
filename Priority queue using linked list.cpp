#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int pri;
    struct node *next;
};

struct node *front = NULL;

void enqueue(int x, int p) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->pri = p;
    t->next = NULL;
    
    if (front == NULL || p < front->pri) {
        t->next = front;
        front = t;
    } else {
        struct node *curr = front;
        while (curr->next != NULL && curr->next->pri <= p) {
            curr = curr->next;
        }
        t->next = curr->next;
        curr->next = t;
    }
    printf("Inserted successfully.\n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow.\n");
        return;
    }
    struct node *t = front;
    printf("Deleted element is %d\n", t->data);
    front = front->next;
    free(t);
}

void display() {
    if (front == NULL) {
        printf("Queue underflow.\n");
        return;
    }
    struct node *curr = front;
    printf("Queue elements: ");
    while (curr != NULL) {
        printf("%d(p:%d) -> ", curr->data, curr->pri);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, priority;
    
    do {

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}
