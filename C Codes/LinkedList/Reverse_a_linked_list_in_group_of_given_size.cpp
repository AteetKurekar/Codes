/*
1->2->3->8->5->9->2->6
pos=4

8->3->2->1->6->2->9->5

*/

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
struct node *reversefunc(struct node *head,int pos){
	if(head==NULL)
		return head;
	struct node *prev=NULL;
	struct node *current=head;
	struct node *next=NULL;
	int count=0;
	while(current!=NULL && count<pos){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	//8->3->2->1->

	//now head->next means 1->
	if(count==pos)
		head->next=reversefunc(current,pos);
	
	//return prev means  8->3->2->1->reversefunc(current,pos)
	return prev;
}


int main(){
	struct node *head1=NULL;
	head1=insert(head1,1);
	head1=insert(head1,2);
	head1=insert(head1,3);
	head1=insert(head1,8);
	head1=insert(head1,5);
	head1=insert(head1,9);
	head1=insert(head1,2);
	head1=insert(head1,6);
	print(head1);
	printf("\n");

	struct node *reverse=head1;
	reverse=reversefunc(reverse,4);
	print(reverse);

}
