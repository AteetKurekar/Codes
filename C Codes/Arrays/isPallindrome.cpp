#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void isPallindrome(char a[],int len){
	int l=0;
	int h=len-1;
	while(l<h){
		if(a[l++]!=a[h--]){
			printf("Not Pallindrome");
			return;
		}
	}
	printf("Is Pallindrome");
	return;
}
int main(){
	char a[]="abbac";
	isPallindrome(a,strlen(a));
}
	
	

