//finding an element of binary search tree in Linked list representation given its key
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
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
		if(data<=(root->data)){
			root->left=insert(root->left, data);
		}
		else{
			root->right=insert(root->right, data);
		}
	}
	return root;
}
struct node *search(struct node* temp, int key){
	if(temp==NULL||temp->data==key){
		return temp;
	}
	else{
		if(temp->data>key)
			search(temp->left, key);
		else
			search(temp->right, key);
	}
}
int main(){
	int sea, insertdata, rootdata;
	struct node* temp;
	struct node* root=NULL;
	printf("Enter the root data of BST: ");
	scanf("%d",&rootdata);
	root=insert(root, rootdata);
	do{
		printf("Enter the data to enter in the BST<0 to stop>: ");
		scanf("%d",&insertdata);
		insert(root, insertdata);
	}while(insertdata!=0);
	printf("Enter the element to search in the BST:\n");
	scanf("%d",&sea);
	temp=search(root, sea);
	if(temp==NULL)
		printf("Data not found\n");
	else
		printf("Element found: %d\n",temp->data);
	return 0;
}
