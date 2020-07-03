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

void detect(struct node *head1,struct node *head2){
	if(head1==head2){
		printf("Both List are of same Index\n");
		return;
	}
	else{
		struct node *current1=head1;
		struct node *current2=NULL;
		while(current1!=NULL){
			current2=head2;
			while(current2!=NULL){
				//printf("Comparing\n%d  %d\n",current1->data,current2->data);
				if(current1==current2){
					printf("there a matching element %d\n",current1->data);
					return;
				}
				else{
					//printf("No matching element\n");
					current2=current2->next;
				}			
			}
			//printf("%d\n",current1->data);
			current1=current1->next;
		}
	}
}
int main(){
	struct node *head1=NULL;
	head1=insert(head1,10);
	head1=insert(head1,20);
	head1=insert(head1,30);
	struct node *current=head1;
	while(current->next!=NULL)
		current=current->next;
	
	head1=insert(head1,40);
	head1=insert(head1,50);
	
	
	print(head1);
	printf("\n");
	
	struct node*head2=NULL;
	head2=insert(head2,5);
	head2=insert(head2,70);
	head2=insert(head2,90);
	head2=insert(head2,80);
	
	struct node *current2=head2;
	while(current2->next!=NULL)
		current2=current2->next;
	current2->next=current;
	print(head2);
	printf("\n");
	detect(head1,head2);

}
