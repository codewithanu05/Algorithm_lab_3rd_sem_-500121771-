#include<stdio.h>
int binarysearch(int arr[],int left,int right,int number){

	

	if(left<=right){
	
		int mid= left +(right-left)/2;
	if(arr[mid]==number){
		return mid;
	}
	else if(arr[mid]>number)
		return binarysearch(arr,left,mid-1,number);
	
     else{
	 
		return binarysearch(arr,mid+1,right,number);
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
	
 int result=	binarysearch(arr,0,n-1,number);
	if(result==-1){
		printf("Element not found");
	}
	else{
		printf("element found at position %d",result);
	}
	
	return 0;
}
