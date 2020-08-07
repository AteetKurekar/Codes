#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createnode(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}
void preorder(struct node *head){
	if(head==NULL){
		return;
	}
	printf("%d ",head->data);
	preorder(head->left);
	preorder(head->right);
}
int main(){
	struct node *head=NULL;

	head=createnode(1);
	head->left=createnode(2);
	head->right=createnode(3);
	head->left->left=createnode(4);
	head->left->right=createnode(5);

	preorder(head);
}
