//store binary tree in array
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
int main(){
	printf("NOTE: This array representation of Binary trees expects tree to be complete\nOR\nThe data are inserted in level order from left to right COMPLETE.\n");
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
	display();
	printf("Inserting value 5 at index 2, the tree will become as: \n");
	insert(2, 5);
	display();
	printf("Deleting element 5.........\n");
	delete(5);
	display();
	return 0;
}
