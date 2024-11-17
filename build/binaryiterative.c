#include<stdio.h>
int binarysearch(int arr[], int size,int number){
	int left=0;
	int right = size-1;
	
	while(left<=right){
		int mid= left +(right-left)/2;
		
		if(arr[mid]==number){
			return mid;
		}
		if(arr[mid]<number){
			left=mid+1;
		}
		if(arr[mid]>number){
			right=mid -1;
		}
	}
	return -1;
	
}
int main(){
	
	int arr[] = {11,21,32,2,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int number;
	printf("Enter the number");
	scanf("%d",&number);
	
 int result=	binarysearch(arr,n,number);
	if(result==-1){
		printf("Element not found");
	}
	else{
		printf("element found at position %d",result);
	}
	
	
	return 0;
}
