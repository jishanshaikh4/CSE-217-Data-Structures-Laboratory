#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root=NULL;
struct node* current;

struct node stack[100];
int top=-1;

void push(struct node data){
	if(top==99){
		printf("stack overflow!\n");
		return;
	}
	else{
		top++;
		stack[top]=data;
	}
}
int pop(){
	struct node* key;
	if(top==-1){
		printf("stack underflow\n");
		return 0;
	}
	else{
		key=&stack[top];
		top--;
	}
	return (key->data);
}
struct node* popstack(){
	struct node* key=&stack[top];
	top--;
	return key;
}
int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
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

void inorder(struct node *root){
	struct node *p;
	p=root;
	printf("The In-order traversal of BST is:\n");
	while(1){
		while(p!=NULL){
			top++;
			stack[top]=*p;
			p=p->left;
		}
		if(top==-1)
			break;
		p=&stack[top];
		top--;
		printf("%d\t",p->data);
		p=p->right;
	}
}
void preorder(struct node *root){
	int flag=0;
	struct node *p=root;
	printf("The Pre-order traversal of BST is:\n");
	while(1){
		while(p!=NULL){
			printf("%d\t",p->data);
			top++;
			stack[top]=*p; //push element onto stack
			if(p->left==NULL && p->right==NULL)
				flag=1; //if left child is present for current node set flag to 1
			p=p->left;
		}
		if(flag==1) //leaf node has been inserted into stack it so pop it out
		{
			p=&stack[top];
			top--;
			flag=0;
		}
		if(top==-1)
			break;
		p=&stack[top]; //get parent node from stack
		top--;
		p=p->right; //now traverse to the right of parent
	}
}
void postorder(struct node* root){
	if(root==NULL)
        	return;
	do{
	    while(root){
           	 if (root->right)
               	 push(*root->right);
           	 push(*root);
            	root = root->left;
       	    }
	    root=popstack();
	    if(root->right && popstack() == root->right){
            	  pop();  // remove right child from stack
          	  push(*root);  // push root back to stack
           	  root = root->right; // change root so that the right
            }
       	    else{
            	printf("%d ", root->data);
            	root = NULL;
            }
	} while (!isempty());
}
int main(){
	int insertdata, choice;
	do{
		printf("\nEnter the data to insert in BST<0 to exit>: ");
		scanf("%d",&insertdata);
		root=insert(root, insertdata);
	}while(insertdata!=0);
	do{
		printf("1. In-order\t2. Pre-order\t3. Post-order\t4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				inorder(root);
				printf("\n");
				break;
			case 2:
				preorder(root);
				printf("\n");
				break;
			case 3:
				postorder(root);
				printf("\n");
				break;
			case 4:
				return 0;
			default:
				printf("Err. Please enter correct choice.\n");
				break;
		}
	}while(choice!=4);
	return 0;
}
