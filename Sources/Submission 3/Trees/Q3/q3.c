//finding an element of binary search tree in array representation given its key
#include <stdio.h>
#include <stdlib.h>

int levelorder[50], size;
void display(){
	printf("The binary tree in level order as inserted was :\n");
	for(int i=0; i<size; i++){
		printf("%d\t",levelorder[i]);
	}
	printf("\n");
	return;
}
void insert(int index, int data){
	size++;
	for(int i=size-1; i>=index; i--)
		levelorder[i+1]=levelorder[i];
	levelorder[index]=data;
	return;
}
void delete(int data){
	int i=0, count=0;
	for(int j=0; j<size; j++){
		if(levelorder[j]==data){
			count++;
		}
	}
	if(count==0){
		printf("Data is not found in the tree !\n");
		return;
		}
	while(i<size){
		if(levelorder[i]==data){
			for(int j=i; j<size; j++){
				levelorder[j]=levelorder[j+1];
			}
			size--;
		}
		i++;
	}
	return;
}
void createtree(){
	int element, i=0;
	printf("Enter the elements in Level order: <0 to stop>: \n");
	while(1){
		scanf("%d",&element);
		if(element==0)
			break;
		else
			levelorder[i++]=element;
	}
	size=i;
}
void search(int key){
	int k=0, counter=0;
	while(k<size){
		if(levelorder[k++]==key){
			printf("Key found at index %d in levelorder traversal of given binary tree\n",k-1);
			counter++;
		}
	}
	if(counter==0){
		printf("KEY not found !");
		return;
	}
}
int main(){
	int searchkey=0;
	printf("NOTE: This array representation of Binary trees expects tree to be complete\nOR\nThe data are inserted in level order from left to right COMPLETE.\n");
	createtree();
	printf("Enter the key you want to search: \n");
	scanf("%d",&searchkey);
	search(searchkey);
	display();
	return 0;
}
