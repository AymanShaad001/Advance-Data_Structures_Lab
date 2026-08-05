#include<stdio.h>//writing stacks using array concept
//arrays are not really prefered due to its inconsistency in holding memory and only suitable to fixed memory sizes

//the stacks follows the concept of LIFO... 
//stack has 2 conditions - insertion done in the end and deletion also at the end where the last element sits
//stack has two operations - insert & pop
int arr[5];
int c=0;

void display(){
	if(c==0){
		printf("The stack is empty...\n");
		return;
	}else{
		for(int i=0;i<c;i++){
			printf("%d->",arr[i]);
		}
		printf("\n");
	}
}

void insert(int x){
	
	if(c==5){//if stack full
		printf("Stack overflow ...\n");
		return;
	}//if elements exists
	arr[c]=x;
	c++;
	display();
}

void pop(){
	if(c==0){
		printf("Stack underflow...\n");
		return;
	}
	printf("element to be deleted is : %d",arr[c-1]);
	c--;
}

void search(int k){
	int d=0;
	int f=0;
	if(c==0){
		printf("Stack empty...\n");
		return;
	}
	for (int i=0;i<c;i++){
		if(arr[i]==k){
			printf("Element %d found at %d position.\n",k,i);
			d++;
			f=1;
		}
	}
	if(f==0){
		printf("The element does not exists in the stack.\n");
	}
	printf("Element found %d times.\n",d);
}


int main(){
	int x,ch,k;
	
	int E=1;
	
	do{
		printf("1.Insert \n2.Pop \n3.Display \n4.Search \n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			
			case 1:
				printf("Enter element to insert:");
				scanf("%d",&x);
				insert(x);
				break;
				
			case 2:
				printf("Popping the last inserted element\n");
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
				printf("Exiting the program   :)");
				E=0;
				break;
				
			default:
				printf("Wrong input...try again...\n");
				break;
		}
	}while(E==1);
	return 0;	
}










