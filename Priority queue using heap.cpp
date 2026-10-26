#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val) {
    if (size >= MAX) {
        printf("Queue overflow.\n");
        return;
    }
    
    // Insert element at the end of the heap
    size++;
    int i = size - 1;
    heap[i] = val;
    
    // Bubble up to maintain min-heap property
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Inserted successfully.\n");
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }
    
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void dequeue() {
    if (size <= 0) {
        printf("Queue underflow.\n");
        return;
    }
    
    printf("Deleted element (highest priority): %d\n", heap[0]);
    
    // Move the last element to the root and reduce size
    heap[0] = heap[size - 1];
    size--;
    
    // Restore the min-heap property
    heapifyDown(0);
}

void display() {
    if (size <= 0) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Priority Queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    do {
        printf("\n--- Priority Queue (Heap) Menu ---\n");
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
                insert(value);
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
