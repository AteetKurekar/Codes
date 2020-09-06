Pushing: 2
Pushing: 3
Pushing: 4
2 3 4
Pushing: 5
Stack overflow
Pushing: 6
Stack overflow
2 3 4
Popping : 3
Pushing: 7
Pushing: 8
Stack overflow
Popping : 3
Popping : 2
Pushing: 9
2 9

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int size=3;
int top=0;
struct node{
	int data;
	struct node *next;
};
struct node *push(struct node *head,int data){
	printf("Pushing: %d\n",data);
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return head;
	}
	top=1;
	struct node *current=head;
	while(current->next!=NULL){
		top++;
		current=current->next;
	}
	if(top==size){
		printf("Stack overflow\n");
		return head;
	}
	else
		current->next=temp;
	return head;
	
}
void pop(struct node *head){
	printf("Popping ");
	if(head==NULL){
		printf("Empty stack\n");return;
	}
	while(head->next->next!=NULL){
		head=head->next;
	}
	printf(": %d\n",head->next->data);
	
	--top;
	free(head->next);
	head->next=NULL;
	return;
}
void print(struct node *head){
	if(head==NULL){
		printf("Empty stack\n");return;
	}
	while(head->next!=NULL){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("%d\n",head->data);
}
int main(){
	struct node *head=NULL;
	head=push(head,2);
	head=push(head,3);
	head=push(head,4);
	print(head);
//	
	push(head,5);
	push(head,6);
	print(head);
	pop(head);
	push(head,7);
	push(head,8);
	pop(head);
	pop(head);
	push(head,9);
	print(head);
}
