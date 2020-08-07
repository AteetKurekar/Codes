#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert(struct node *head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	if(head==NULL){
		head=temp;
		return head;
	}
	if(data<head->data){
		head->left=insert(head->left,data);
		return head;
	}
	else if(data>head->data){
		head->right=insert(head->right,data);
		return head;
	}
}

void print(struct node *head){
	if(head==NULL){
		return;
	}
	print(head->left);
	printf("%d ",head->data);
	print(head->right);
}
int main(){
	struct node *head=NULL;
	head=insert(head,8);
	head=insert(head,6);
	head=insert(head,10);
	head=insert(head,4);
	head=insert(head,7);
	head=insert(head,9);
	head=insert(head,11);
	head=insert(head,3);
	head=insert(head,5);
	print(head);
}
