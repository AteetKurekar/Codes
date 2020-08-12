Given two arrays X and Y of positive integers, 
find number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.


#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>

int main(){
	int a[]={2,1,6};
	int b[]={1,5};
	
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		for(int j=0;j<sizeof(b)/sizeof(b[0]);j++){
			printf("Comparing %d %d ",a[i],b[j]);
			if(pow(a[i],b[j]) > pow(b[j],a[i]))
				printf("Matched\n");
			else
				printf("\n");
		}
	}
}
