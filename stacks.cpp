#include<stdio.h>
#include<malloc.h>//headers

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL;
struct node *temp=NULL;
//initial declarations of pointers

// stacks has two operations - insert & pop
//insert inserts the block 
//pop removes the top most block or the last inserted block

void display(){
	struct node *t;
	t=top;
	if(top==NULL){
		printf("Stack is empty...\n");
	}else{
		while(t!=NULL){
			printf("%d->",t->data);
			t=t->next;
		}
		printf("\n");
	}	
}

void insert(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=top;
	top=temp;
	display();
}

void pop(){
	struct node *t;
	t=top;
	if(top==NULL){
		printf("Stack underflow...\n");
	} else {
    	t = top;                            
    	printf("Popped element is : %d\n", t->data); 
    	top = top->next;                    
    	free(t);                            
	}
	display();
}

void search(int k){
	struct node *t=top;
	int c=0;
	int f =0;
	if(top==NULL){
		printf("List is empty...");
		return;
	}
	while(t!=NULL){
		c++;
		if(t->data==k){
			printf("%d value found %d position",k,c);
			f=1;
		}
		t=t->next;
	}
	if(f==0){
		printf("Value not found in the stack...");
	}
}

int main(){
	int k, ch, x;
	int C=1;
	while(C==1){
		printf("\n1.Insert \n2.Pop \n3.Display \n4.Search \n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value to be inserted :");
				scanf("%d",&x);
				insert(x);
				break;
				
			case 2:
				printf("The top most element will be popped...");
				pop();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				printf("Enter element to search :");
				scanf("%d",&k);
				search(k);
				break;
			
			case 5:
				C=0;
				printf("Terminating the program...");
				break;
			
			default:
				printf("Invalid input...try again");
				break;
		}
	}
	return 0;
}




