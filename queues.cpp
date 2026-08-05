#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;//a queue follows FIFO-first in first out... 
	
};

struct node *temp =NULL;//blocks are inserted at the end , and removed from the top
struct node *front=NULL;//a queue follows FIFO-first in first out... 
struct node *rear=NULL;

//imp notes*-
//queue has 2 operations- insertion , deletion 
// deletion happens from the front and insertion happens from the rear end
//for this program - works only for uni directional queue


void display(){//the display function is usually prefered to be at the start 
	struct node *t=front;//because the compiler reads the functions first before being called...
	int c=0;
	while(t!=NULL){
		printf("%d->",t->data);
		t=t->next;
		c++;
	}
	printf("\nQueue size is: %d",c);
	printf("\n");
}

//remember to declare global variable C for counts of elements in queue
void enque(int x){
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL){
		front=temp;
		rear=temp;
	}else{
		rear->next=temp;
		rear=temp;
	}
}

void deque(){
	struct node *t=front;
	if(front==NULL){
		printf("Underflow condition...Queue empty");
		return;
	}else{
		printf("Removed element is: %d",t->data);
		front=front->next;
		free(t);
		
	}
}



void search(int k){
	struct node *t=front;
	int p=1;
	int f=0;
	if(front==NULL){
		printf("Queue is empty...");
		return;
	}
	while(t!=NULL){
		if(t->data == k){
			printf(" %d value found at %d position\n",k,p);
			f=1;
		}
		t=t->next;
		p++;
	}
	if(f==0){
		printf("Value not found in the queue...");
	}
}

int main(){
	int x,k,ch;
	int B=1;
	do{
		printf("\n1.Enque \n2.Deque \n3.Display \n4.Search \n5.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch){
			
			case 1:
				printf("Enter the value to Enque: ");
				scanf("%d",&x);
				enque(x);
				display();
				break;
				
			case 2:
				printf("Removes the rear element...");
				deque();
				display();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				printf("Enter value to search in the Queue :");
				scanf("%d",&k);
				search(k);
				break;
				
			case 5:
				printf("Exiting the program...");
				B=0;
				break;
				
			default:
				printf("Wrong input...try again..\n");
				break;
		}
	}while(B==1);
	return 0;
}



