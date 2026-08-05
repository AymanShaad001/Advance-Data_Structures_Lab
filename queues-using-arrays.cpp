#include<stdio.h>//queues using arrays 

//queues has 2 operations - insertion at the rear , and deletion at the front
//arrays for queues just like stacks arent really recommended because of there limitations on memory accessing.

int arr[5];
int f=-1;
int r=-1;


void enque(int x){
	if (r==5){
		printf("Queue overflow.\n");
		return;
	}if (f==-1){
		arr[0]=x;
		f++;
		r++;
	}else{
		r++;
		arr[r]=x;
	}
	
}

void deque(){
	if(f==-1){
		printf("Queue underflow.\n");
		printf("Queue empty.\n");
		return;
	}else if(f==r){
		f=-1;
		r=-1;
	}else{
		printf("removing element %d from the queue.\n",arr[f]);
		f++;
	}
}

void display(){
	if(f==-1){
		printf("Queue is empty.\n");
		return;
	}else{
		for(int i=f;i<=r;i++){
			printf("%d->",arr[i]);
		}
		printf("\n");
	}
}

void search(int k){
	int p=0;
	int found=0;
	if(f==-1){
		printf("Queue is empty.\n");
		return;
	}else{
		for(int i=f;i<=r;i++){
			if(arr[i]==k){
				printf("Element %d found at %d position.\n",k,p);
				found=1;
			}
		p++;	
		}
	}
	if(found==0){
		printf("Element not found in the queue.\n");
	}else{
		printf("Total count of elements found is :%d",p);
	}
}

int main(){
	int x,ch,k;
	int Y=1;
	do{
		printf("\n1.Enque \n2.Deque \n3.Display \n4.Search \n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			
			case 1:
				printf("Enter element to insert into the queue: ");
				scanf("%d",&x);
				enque(x);
				display();
				break;
			
			case 2:
				printf("perfroming dequeue\n");
				deque();
				display();
				break;
				
			case 3:
				display();
				break;
			
			case 4:
				printf("Enter element to search: ");
				scanf("%d",&k);
				search(k);
				break;
				
			case 5:
				printf("Terminating the program.\n");
				Y=0;
				break;
			
			default:
				printf("Invalid input..try again.\n");
				break;
		}
	}while(Y==1);
	return 0;
}




























