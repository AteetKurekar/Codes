#include<stdlib.h>
#include<stdio.h>
int main() 
{ 
	int a[] = {5,1,7,3,6,7,8,10,11,9}; 
	int n = sizeof a / sizeof a[0]; 
	int max=a[0],flag=0;
	for(int i=1;i<n;i++){
		flag=0;
		if(max>a[i])
			continue;
			
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				max=a[i];
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("At Position: %d\n",i);
	}
	
} 
