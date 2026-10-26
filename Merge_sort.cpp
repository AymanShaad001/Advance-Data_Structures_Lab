#include<stdio.h>

void merge(int a[],int low,int mid,int high){
	int i=low,j=mid+1,k=0;
	int b[30];
	
	while(i<=mid && j<=high){
		if(a[i]<a[j]){
			b[k++]=a[i++];
		}else{
			b[k++]=a[j++];
		}
	}
	while(i<=mid){
		b[k++]=a[i++];
	}
	while(j<=high){
		b[k++]=a[j++];
	}
	for(i=0; i<k; i++){
		a[low+i]=b[i];
	}
}

void merge_sort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main(){
	int a[30],n;
	
	do{
		printf("Enter number of elements (30->max):");
		scanf("%d",&n);
	    if(n<0){
		    printf("Invalid input.Elements cannot be negative\n");															
	    }
	    if(n==0){
		    printf("Array is empty.\n");  
		}
		if(n > 30){
			printf("Invalid input.Size greater than max capacity\n");
		}
			
	}while(n<=0 || n>30);

	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	merge_sort(a,0,n-1);

	printf("Sorted array:\n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}














