#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

void middle(){
	struct node *fast=head;
	struct node *slow=head;
	if(head==NULL){
		printf("List is Empty");
		return;
	}
	if(head->next==NULL){
		printf("%d\n",head->data);
		return;
	}
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	printf("%d\n",slow->data);

}

void deletepos(int pos){
	if(head==NULL){
		printf("List is Empty\n");
		return;
	}
	else{
		int count=1;
		struct node *current=head;
		struct node *prev=head;//often confusion happens in defining "prev" as NULL
		//if you define prev=NULL you will lose head pointer while deleting pos=1 element and hence the list 
		
		while(current->next!=NULL && count<pos){
			count++;
			prev=current;
			current=current->next;
		}
		if(count==pos){
			prev->next=current->next;
			if(pos==1){
				head=prev;
			}
			free(current);		
		}
	}
}

void reverse(struct node *temp){
	if(temp==NULL){
		//printf("No elements");
		return;
	}
	reverse(temp->next);
	printf(" %d",temp->data);
}
void insert(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL){
		head=temp;
		return;
	}
	else{
		struct node *current=head;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
	}
}
void print(){
	if(head==NULL){
		printf("List is empty");
		return;
	}
	struct node *current=head;
	while(current->next!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("%d",current->data);
	
}
int main(){
	int choice;
	while(1){
		int n;
		printf("\nEnter your choice\n");
		printf("1.Insert\n");
		printf("2.Print\n");
		printf("3.Reverse\n");
		printf("4.Delete an element of given position\n");
		printf("5.Middle element without using position\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter an element\n");
				//scanf("%d",&n);
				insert(10);insert(20);insert(30);
				break;
			case 2:
				print();
				break;
			case 3:
				reverse(head);
				break;
			case 4:
				printf("Enter position\n");
				scanf("%d",&n);
				deletepos(n);
			case 5:
				middle();
				break;
		}
		printf("\nWant to stop enter 0: ");scanf("%d",&n);
		if(n==0)
			break;

	}
}
