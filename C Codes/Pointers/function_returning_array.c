#include<stdio.h>
int (*function())[5]{
	int arr[5] = {2, 3, 5, 7, 11};
//	printf("%d", *arr);
	return &arr;
}
int main(){
	int (*ptr)[5];
	ptr = function();
	printf("%d ", *(*ptr+1));
	return 0;
}
