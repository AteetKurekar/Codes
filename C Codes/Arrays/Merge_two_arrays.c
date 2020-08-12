/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 


void merge(int arr1[],int arr2[],int size1,int size2){
	int temp[size1+size2];
	int count=0;
	int i=0,j=0;
	while(i<size1 && j<size2){
		if(arr1[i]>arr2[j]){
			temp[count++]=arr2[j++];
		}
		else{
			temp[count++]=arr1[i++];
		}	
	}
	if(i<size1){
		while(i<size1)
			temp[count++]=arr1[i++];
	}
	if(j<size2){
		while(j<size2)
			temp[count++]=arr2[j++];
	}
	for(int i=0;i<size1+size2;i++){
		printf("%d ",temp[i]);
	}
}

int main(){
	int arr1[]={10,20};
	int arr2[]={1,2,3,4};
	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	merge(arr1,arr2,size1,size2);
	
}
