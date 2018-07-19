//Traverse BST in inorder, pre and post-order using recursion
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
void postorder(struct node* root){
	if(root==NULL){
		return;
	}
	else{
		preorder(root->left);
		preorder(root->right);
		printf("%d\t",root->data);
	}
}
int main(){
	struct node *root=NULL;
	int rootdata, insertdata;
	printf("Enter the root data for BST: ");
	scanf("%d",&rootdata);
	root=insert(root, rootdata);
	do{
		printf("Enter the data to insert in BST<0 to exit>: ");
		scanf("%d",&insertdata);
		root=insert(root, insertdata);
	}while(insertdata!=0);
	printf("The Inorder traversal of BST is\n");
	inorder(root);
	printf("\nThe Pre-order traversal of BST is\n");
	preorder(root);
	printf("\nThe Post-order traversal of BST is\n");
	postorder(root);
	printf("\n");
	return 0;
}
