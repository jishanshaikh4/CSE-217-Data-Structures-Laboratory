#include <stdio.h>
#include <stdlib.h>
int arr[500];
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
struct node* newnode(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node* insert(struct node* root, int data){
	if(root==NULL){
		root=newnode(data);
		return root;
	}
	else{
		if(data<=root->data){
			root->left=insert(root->left, data);
		}
		else{
			root->right=insert(root->right, data);
		}
		return root;
	}
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
int main(){
	int i,n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("\nEnter the elements of unsorted array :\n");
	for(i=0; i<n; i++){
			scanf("%d",&arr[i]);
			root=insert(root, arr[i]);
	}
	printf("The inorder traversal of given unsorted array converted to BST is :\n");
	inorder(root);
	printf("\n");
	return 0;
}
