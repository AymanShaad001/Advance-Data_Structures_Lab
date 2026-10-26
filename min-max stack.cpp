#include<stdio.h>
#define MAX 10
int stack[MAX], max_stack[MAX], min_stack[MAX];
int top=-1;

void push(int x){
	if(top==MAX-1){
		printf("stack overflow.\n");
	}else{
		if(top==-1){
			top++;
			stack[top]=x;
			max_stack[top]=x;
			min_stack[top]=x;
		}else{
			top++;
			stack[top]=x;
			if(x>max_stack[top-1]){
				max_stack[top]=x;
				min_stack[top]=min_stack[top-1];
			}else if(x<min_stack[top-1]){
				min_stack[top]=x;
				max_stack[top]=max_stack[top-1];
			}else{
				max_stack[top]=max_stack[top-1];
				min_stack[top]=min_stack[top-1];
			}
		}
	}
}

int pop(){
	if(top==-1){
		return -1;
	}
	return (stack[top--]);
}

int max(){
	return (max_stack[top]);
}
int min(){
	return (min_stack[top]);
}

void display(){
	if(top==-1){
		printf("Stack underflow.\n");
	}else{
		for(int i=top;i>=0;i--){
			printf("%d:",stack[i]);
		}
		printf("Max element is %d\n",max());
		printf("Min element is %d\n",min());
	}
}

int main(){
	int ch, j, x;
	do{
		printf("Push:\n");
		printf("Pop:\n");
		printf("display:\n");
		printf("Enter choice:");
		printf("Exit:\n");
		scanf("%d",&ch);
		switch(ch){
			
			case 1:
				printf("Enter element to push:");
				scanf("%d",&x);
				push(x);
				display();
				break;
				
			case 2:
				printf("Poping last entered element:\n");
				pop();
				display();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				ch=0;
				break;
				
			default:
				printf("Invalid entry");
				
		}
	}while(ch);
	return 0;
}
