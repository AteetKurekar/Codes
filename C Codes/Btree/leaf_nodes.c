#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int printLeafNodes(struct node *root) 
{ 
    // if node is null, return 
    if (root==NULL) 
        return 0; 
      
    // if node is leaf node, print its data     
    if (root->left==NULL && root->right==NULL) 
    { 
    	printf("%d ",root->data);
        return 1; 
    } 
  
       return printLeafNodes(root->left)+printLeafNodes(root->right); 
}
struct node *createnode(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}

int main(){
	struct node *head=NULL;

	head=createnode(1);
	head->left=createnode(2);
	head->right=createnode(3);
	head->left->left=createnode(4);
	head->left->right=createnode(5);
//	printlevelorder(head);
printf("Leaf Nodes ");
printf("\ncount of leaf nodes: %d",printLeafNodes(head));

}
