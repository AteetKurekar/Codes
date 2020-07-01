#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

void duplicate(){
	struct node *current=head;
	
	while(current->next->next!=NULL){
		struct node *trav=current->next;
		struct node *prev=current;
		while(trav->next!=NULL){
			if(current->data==trav->data){
				prev->next=trav->next;
				struct node*temp=trav;
				trav=trav->next;
				free(temp);
			}
			else{
				prev=trav;
				trav=trav->next;
			}
		}
		if(current->data==trav->data){
			prev->next=trav->next;
			free(trav);
		}
		current=current->next;	
	}
	if(current->data==current->next->data){
		current->next=NULL;
		free(current->next);
	}
	return;
}

void swap(struct node *current , struct node *trav){
	int d=current->data;
	current->data=trav->data;
	trav->data=d;
	trav=trav->next;
}
void sort(){
	struct node *current=head;
	
	while(current->next->next!=NULL){
		struct node *trav=current->next;
		while(trav->next!=NULL){
			if(current->data > trav->data){
				swap(current,trav);
			}
			else
				trav=trav->next;
		}
		//if pointer on last element and that element is small to the current->data
		if(current->data > trav->data){
				swap(current,trav);
			}
		//else increment current	
		else
			current=current->next;
	}
	
	//if current is on last sencond index and trav on last
	if(current->data > current->next->data){
		swap(current,current->next);
	}
	else
		return;
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
int main(){
	insert(20);
	insert(20);
	insert(10);
	insert(70);
	insert(80);
	insert(90);
	insert(2);
	insert(50);
	insert(5);
	printf("unsorted list\n");
	print();
	duplicate();
	printf("\n\n");
	printf("filtered list\n");
	print();
	sort();
	printf("\n\n");
	printf("sorted list\n");
	print();
	
}
