Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively 
i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...
1 2 3 4 5 6
=>6 1 5 2 4 3
Note;Array must be sorted
/* C program for Merge Sort */
#include <stdio.h> 
#include <stdlib.h> 


int main(){
	int a[]={1,2,3,4,5};
	int size=sizeof(a)/sizeof(a[0]);
	int temp[size];
	int l=0,h=size-1;
	
	for(int i=0;i<size;i++){
		if(i%2==0)
			temp[i]=a[h--];
		else
			temp[i]=a[l++];	
	}
	for(int i=0;i<size;i++){
		printf("%d ",temp[i]);
	}
}
