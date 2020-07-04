#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void print(struct node *head){
	if(head==NULL)
		printf("List is Empty");
	else{
		struct node *current=head;
		while(current->next!=NULL){
			printf("%d ",current->data);
			current=current->next;
		}
		printf("%d",current->data);
	}
}
struct node *insert(struct node *head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
		//printf("Node Inserted at head\n");
		return head;
	}
	else{
		struct node *current=head;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
		//printf("Node Inserted at end\n");
		return head;
	}
}
void detect(struct node *head){
	if(head==NULL || head->next==NULL){
		printf("List empty or single element only\n");
		return;
	}
		
	struct node *slow=head->next;
	struct node *fast=slow->next;
	
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next->next;
	}
//	printf("%d %d %d\n",slow,fast,slow->data);
	slow=head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	printf("Loop is at Address :%d\nData: %d",fast,slow->data);
}

int main(){
	struct node *head1=NULL;
	head1=insert(head1,1);
	head1=insert(head1,2);
	head1=insert(head1,3);
	struct node *current=head1;
	while(current->next!=NULL)
		current=current->next;
	head1=insert(head1,4);
	head1=insert(head1,5);
	struct node *current2=head1;
	while(current2->next!=NULL)
		current2=current2->next;
	current2->next=current;
	//print(head1);
	detect(head1);

}
