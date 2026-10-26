#include<stdio.h>
#define MAX 10

int undo_stack[MAX], redo_stack[MAX];
int tu = -1, tr = -1;

void push_undo(int x);
void push_redo(int x);

void insert(int x){
    if(tu == MAX-1){
        printf("Stack overflow.\n");
    } else {
        push_undo(x);
        tr = -1; 
        printf("Inserted: %d\n", x);
    }
}

void undo(){
    if(tu == -1){ 
        printf("Undo not possible.\n");
    } else {
        int x = undo_stack[tu];
        tu--;
        push_redo(x);
        printf("Undo performed. Value: %d\n", x);
    }
}

void push_undo(int x){
    if(tu == MAX-1){
        printf("Overflow.\n");
    } else {
        tu++;
        undo_stack[tu] = x; 
    }
}

void redo(){
    if(tr == -1){
        printf("Redo not possible.\n");
    } else {
        int x = redo_stack[tr];
        tr--;
        push_undo(x);
        printf("Redo performed. Value: %d\n", x);
    }
}

void push_redo(int x){
    if(tr == MAX-1){
        printf("Overflow.\n");
    } else {
        tr++;
        redo_stack[tr] = x;
    }
}

void display(){
    if(tu == -1){
        printf("Stack is empty.\n");
    } else {
        printf("Current Elements in Undo Stack: ");
        for(int i = 0; i <= tu; i++){
            printf("%d ", undo_stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, val;
    
    do {
        printf("\n1. Insert (Perform Action)\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                undo();
                break;
            case 3:
                redo();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}
