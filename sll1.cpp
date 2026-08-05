#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;
struct node *temp=NULL;

void create(int n){
	struct node *t;
	for(int i=0;i<n;i++){
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			t=head;
		}else{
			t->next=temp;
			t=temp;
		}
	}
}

void insbeg(int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}else{
		temp->next=head;
		head=temp;
	}
}

void insend(int x){
	struct node *t;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}else{
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=temp;
	}
}

void inspos(int x, int pos){
	int c=1;
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}else{
		t=head;
		while(c<pos-1){
			t=t->next;
			c++;
		}
		temp->next=t->next;
		t->next=temp;
	}
}

void delbeg(){
	if(head==NULL){
		printf("List is empty\n");
	}else{
		temp=head;
		printf("Deleted node info is %d\n",temp->data);
		head=head->next;
		free(temp);
	}
}

void delend(){
	temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	printf("\nDeleted node info is %d",temp->data);
	free(temp->next);
	temp->next=NULL;
}

void delpos(int pos){
	int c=1;
	struct node *t;
	temp=head;
	while(c<pos-1){
		temp=temp->next;
		c++;
	}
	t=temp->next;
	temp->next=t->next;
	printf("\nDeleted node info is %d",t->data);
	free(t);
}

void search(int k){
	temp=head;
	int c=0;
	while(temp!=NULL){
		if(temp->data==k){
			
			printf("%d Value found at %d position ",k,c);
			
		}
		temp=temp->next;
		c++;
	}
	printf("Value not found...");
}

void display(){
	temp=head;
	if(temp == NULL) {
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main(){
	int ch,k,pos,x,n;
	do{
		printf("\n1.Create\n2.Display\n3.Search\n4.Insert at beginning\n5.Insert at End\n6.Insert at Position\n");
		printf("7.Delete from beginning\n8.Delete from End\n9.Delete from Position\n10.Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter no of nodes: ");
				scanf("%d",&n);
				create(n);
				display();
				break;
			
			case 2:
				display();
				break;
			
			case 3:
				printf("Enter element to search: ");
				scanf("%d",&k);
				search(k);
				break;
				
			case 4:
				printf("Enter element to insert at beginning :");
				scanf("%d",&x);
				insbeg(x);
				display();
				break;
			
			case 5:
				printf("Enter element to insert at end :");
				scanf("%d",&x);
				insend(x);
				display();
				break;
				
			case 6:
				printf("Enter element to insert at position :");
				scanf("%d",&x);
				printf("Enter position :");
				scanf("%d",&pos);
				inspos(x,pos);
				display();
				break;
				
			case 7:
				delbeg();
				display();
				break;
			
			case 8:
				delend();
				display();
				break;
				
			case 9:
				printf("Enter position to delete element:");
				scanf("%d",&pos);
				delpos(pos);
				display();
				break;
		}
    }while(ch!=10);
    return 0;	
}
