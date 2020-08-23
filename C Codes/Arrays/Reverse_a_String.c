#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
	char a[]="ateet kurekar is a good boy";
	int l=0,h=strlen(a)-1;
	while(l<h){
		char temp=a[l];
		a[l++]=a[h];
		a[h--]=temp;
	}
	for(int i=0;i<strlen(a);i++){
		printf("%c ",a[i]);
	}
}
