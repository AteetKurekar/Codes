Pushing 1
Pushing 2
Pushing 3
Pushing 4
Stack Overflow
1 2 3
Popping: 3
Pushing 5
Pushing 6
Stack Overflow
Popping: 5
Pushing 7
1 2 7



#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int stack[3];
int top=-1;
void push(int data){
	cout<<"Pushing "<<data<<endl;
	if(top<2){
		stack[++top]=data;
		return;
	}
	else
		cout<<"Stack Overflow\n";
		return;
}
void pop(){
	if(top==-1)
		cout<<"Stack Underflow\n";
	if(top<=2)
		printf("Popping: %d\n",stack[top--]);
}
void print(){
	for(int i=0;i<=top;++i)
		printf("%d ",stack[i]);
	cout<<endl;
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	print();
	pop();
	push(5);
	push(6);
	pop();
	push(7);
	print();
}
