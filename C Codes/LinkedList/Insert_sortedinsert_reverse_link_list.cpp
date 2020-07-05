#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
void print(struct node *head){
	if(head==NULL){
		printf("List is empty");
		return;
	}
	struct node *current=head;
	while(current->next!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("%d\n",current->data);
}
struct node *insert(struct node *head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(head==NULL){
		head=temp;
		//printf("Node Inserted at head\n");
		return head;
	}
	
	struct node *current=head;
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=temp;
	//printf("Node Inserted at end\n");
	current->next=temp;
	temp->prev=current;
	return head;
}
struct node *reverse(struct node *head){
	if(head==NULL || head->next==NULL)
		return head;
	struct node *current=head;
	struct node *next=current->next;
	struct node *prev=NULL;
	
	while(current!=NULL){
		current->prev=next;
		current->next=prev;
		prev=current;
		current=next;
		if(current==NULL)
			next=NULL;
		else
			next=current->next;
	}
	
	return prev;
}
struct node *sortedinsert(struct node *head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(head==NULL){
		head=temp;
		return head;
	}
	
	struct node *current=head;
	if(head->data > data){
		head=temp;
		head->next=current;
		current->prev=head;
		return head;	
	}
	while(current->next!=NULL && data >= current->next->data){
		current=current->next;
	}
	
	struct node *temp2=current->next;
	current->next=temp;
	temp->prev=current;
	temp->next=temp2;
	return head;
}
int main(){
	struct node *head=NULL;
	head=sortedinsert(head,2);
	head=sortedinsert(head,3);
	head=sortedinsert(head,4);
	head=sortedinsert(head,1);
	print(head);
	head=reverse(head);
	print(head);
	
	//print(head);
}
