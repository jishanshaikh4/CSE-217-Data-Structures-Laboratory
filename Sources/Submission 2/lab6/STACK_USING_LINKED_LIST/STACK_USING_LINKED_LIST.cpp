#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct node{
 int item;
 struct node *next;
};

struct node * Insert(struct node *root,int data){

 struct node *n;
 n=(struct node*)malloc(sizeof(struct node));
 n->next=NULL;
 n->item=data;
 if(root==NULL){
  root=n;
 }
 else{
  struct node *par;
  par=root;
   while(par->next!=NULL){
     par=par->next;
   }
   par->next=n;
 }
 return(root);
}

struct node * Delete(struct node *root){
 struct node *p, *q;
 p=q=root;
 while(p->next!=NULL){
  q=q->next;
  p=q->next;
 }  
 q->next=NULL;
 printf("Popped Item is :%d\n",p->item);
 free(p);
 return(root);
}

struct node* Traverse (struct node *root){
 struct node *tar;
 tar=root;
 while(tar!=NULL){
   printf("%d ",tar->item);
  tar=tar->next;
 }
 return(root);
}
int main(){
 int choice,data;
 struct node *root=NULL;
 while(true){
 printf("\nEnter your choice\n1: PUSH\n2: POP\n3: OVERVIEW\n4: EXIT\n");
 scanf("%d",&choice);
 printf("\n");
 switch(choice){
 case 1: 
       printf("Enter Data: ");
       scanf("%d",&data);
       root=Insert(root,data);
       break;
 case 2:
       root=Delete(root);
       break;
 case 3:
       root=Traverse(root);
       break;
 case 4:
       exit(0);      
 }
}
 return 0;
}
    
