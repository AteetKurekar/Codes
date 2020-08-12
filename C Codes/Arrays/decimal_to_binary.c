#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int arr[10];
	int n=6;
	int count=0;
	while(n>0){
		arr[count++]=n%2;
		n=n/2;
	}
	for(int i=count-1;i>=0;i--){
		printf("%d ",arr[i]);
	}
}
