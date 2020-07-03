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


void insert2(struct node **head,int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(*head==NULL){
		*head=temp;
		//printf("Node Inserted at head\n");
		return;
	}
	else{
		struct node *current=*head;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
		//printf("Node Inserted at end\n");
		return;
	}
}

int main(){
//insert using return pointer
	struct node *head1=NULL;
	head1=insert(head1,10);
	head1=insert(head1,20);
	head1=insert(head1,30);
	print(head1);
	printf("\n");
	
  //insert using double pointer
	struct node *head2=NULL;
	insert2(&head2,10);
	insert2(&head2,20);
	insert2(&head2,30);
	print(head2);

}
