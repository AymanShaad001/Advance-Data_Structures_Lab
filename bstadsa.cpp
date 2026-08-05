#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root=NULL;
int foundDelete=0;

struct node* createNode(int x){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

void insert(int x){
    struct node *temp=createNode(x);
    if(root==NULL){
        root=temp;
        printf("%d inserted as the root node.\n",x);
        return;
    }
    struct node *p=root,*parent=NULL;
    while(p!=NULL){
        parent=p;
        if(x<p->data)
            p=p->left;
        else if(x>p->data)
            p=p->right;
        else{
            printf("Duplicate element. Insertion is not allowed.\n");
            free(temp);
            return;
        }
    }
    if(x<parent->data)
        parent->left=temp;
    else
        parent->right=temp;
    printf("%d inserted successfully.\n",x);
}

void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}

void search(int x){
    struct node *p=root;
    while(p!=NULL){
        if(x==p->data){
            printf("\nElement %d found in the Binary Search Tree.\n",x);
            return;
        }
        else if(x<p->data)
            p=p->left;
        else
            p=p->right;
    }
    printf("\nElement %d not found in the Binary Search Tree.\n",x);
}

struct node* minValue(struct node *p){
    while(p->left!=NULL)
        p=p->left;
    return p;
}

struct node* deleteNode(struct node *p,int x){
    if(p==NULL)
        return NULL;
    if(x<p->data)
        p->left=deleteNode(p->left,x);
    else if(x>p->data)
        p->right=deleteNode(p->right,x);
    else{
        foundDelete=1;
        if(p->left==NULL){
            struct node *temp=p->right;
            free(p);
            return temp;
        }
        else if(p->right==NULL){
            struct node *temp=p->left;
            free(p);
            return temp;
        }
        else{
            struct node *temp=minValue(p->right);
            p->data=temp->data;
            p->right=deleteNode(p->right,temp->data);
        }
    }
    return p;
}

void createBST(){
    int n,x,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Tree is empty.\n");
        return;
    }
    printf("Enter %d node values:\n",n);
    for(i=1;i<=n;i++){
        printf("Enter value %d: ",i);
        scanf("%d",&x);
        insert(x);
    }
    printf("\nBinary Search Tree created successfully.\n");
    printf("Current BST (Inorder Traversal): ");
    inorder(root);
    printf("\n");
}

int main(){
    int ch,x;

    createBST();

    while(1){

        printf("\n1. Insert a Node");
        printf("\n2. Search for a Node");
        printf("\n3. Delete a Node");
        printf("\n4. Display Inorder Traversal");
        printf("\n5. Display Preorder Traversal");
        printf("\n6. Display Postorder Traversal");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&x);
                insert(x);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d",&x);
                search(x);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d",&x);
                foundDelete=0;
                root=deleteNode(root,x);
                if(foundDelete)
                    printf("Element %d deleted successfully.\n",x);
                else
                    printf("Element %d is not present to delete.\n",x);
                break;

            case 4:
                if(root==NULL)
                    printf("Tree is empty.\n");
                else{
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 5:
                if(root==NULL)
                    printf("Tree is empty.\n");
                else{
                    printf("Preorder Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;

            case 6:
                if(root==NULL)
                    printf("Tree is empty.\n");
                else{
                    printf("Postorder Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 7:
                printf("\nProgram Executed Successfully.\n");
                exit(0);

            default:
                printf("Invalid Choice! Please enter a choice between 1 and 7.\n");
        }
    }
    return 0;
}
