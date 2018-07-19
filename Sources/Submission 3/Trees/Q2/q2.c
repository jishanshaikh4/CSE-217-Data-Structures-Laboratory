//store binary tree in a linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *insert(int data){
	struct node* temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void inorder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	struct node *root=insert(5);
	root->left=insert(3);
	root->right=insert(6);
	(root->left)->left=insert(2);
	(root->left)->right=insert(3);
	printf("The data of ((root->left)->left) is %d\n",((root->left)->left)->data);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	return 0;
}
