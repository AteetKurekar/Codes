Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33
#include<stdlib.h>
#include<stdio.h>

int main(){
	
		int num=15;
		int arr[]={1, 4, 0, 0, 3, 10, 5};
		int n=sizeof(arr)/sizeof(arr[0]);
		int i,j;
		for(i=0;i<n-1;i++){
			int sum=arr[i];
			for(j=i+1;j<n;j++){
				sum+=arr[j];
				if(sum>=num)
					break;
			}
			if(sum==num){
				printf("position: %d to %d\n",i+1,j+1);
				return 0;
			}	
		}	    	

	printf("No positions");
}
