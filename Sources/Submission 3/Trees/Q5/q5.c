//Program to find maximum depth of a BST
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int data){
	struct node* Node=(struct node *)malloc(sizeof(struct node));
	Node->data=data;
	Node->left=NULL;
	Node->right=NULL;
	return Node;
}
struct node* insert(struct node* root, int data){
	if(root==NULL){
		root=newnode(data);
		return root;
	}
	else{
		if(data<=(root->data)){
			root->left=insert(root->left, data);
		}
		else{
			root->right=insert(root->right, data);
		}
	}
	return root;
}
int maxdepth(struct node* root){
	int rdepth, ldepth;
	if(root==NULL){
		return 0;
	}
	else{
		rdepth=maxdepth(root->right);
		ldepth=maxdepth(root->left);
		if(rdepth>ldepth){
			return (rdepth+1);
		}
		else{
			return (ldepth+1);
		}
	}
}
int main(){
	int option, data;
	struct node* root=NULL;
	do{
		printf("1. Insert\t2. Find Maxdepth\t3. Exit\n");
		printf("Enter the option: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\nEnter the data to enter in BST: ");
				scanf("%d",&data);
				root=insert(root, data);
				break;
			case 2:
				printf("The maximum depth of the BST is: %d\n", maxdepth(root));
				break;
			case 3:
				return 0;
			default:
				printf("Err...  Please enter correct option !!!\n");
		}
	}while(option!=3);
	return 0;
}
