#include<stdio.h>
#include<stdlib.h>
#define max_size 500
int stack[max_size],top=-1;

void push();
void pop();
void peek();
void display();

int main(){
        int choice;
        do{
                
                printf("\n\n**********MAIN MENU**********\n");
                printf("1.Push\n");
                printf("2.Pop\n");
                printf("3.Peep\n");
                printf("4.Display\n");
                printf("5.Exit\n");
                printf("*********************************");
                
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                
                switch(choice){
                        case 1: 
                                        push();
                                        break;
                        case 2:
                                        pop();
                                        break;
                        case 3:
                                        peek();
                                        break;
                        case 4:
                                        display();
                                        break;
                        case 5:
                                        exit(0);
                                        break;
                        default:
                                        printf("\nInvalid choice:\n");
                                        break;
                }
        }while(choice!=5);
	return 0;
}
void push(){
        int item;
        if(top==(max_size-1)){
                printf("\nStack Overflow:");
        }
        else{
                printf("Enter the element to be inserted:\t");
                scanf("%d",&item);
                top=top+1;
                stack[top]=item;
        }
}
void pop(){
        int item;
        if(top==-1){
                printf("Stack Underflow:");
        }
        else{
                item=stack[top];
                top=top-1;
                printf("\nThe poped element: %d\t",item);
        }
}
void peek(){
        if(top==-1){
                printf("\nStack is empty:");
        }
        else{
                printf("The topmost element of the stack is %d",stack[top]);
        }
}
void display(){
        int i;
        if(top==-1){
                printf("\nStack is Empty:");
        }
        else{
        	printf("\nThe stack elements are:\n" );
        	for(i=top;i>=0;i--){	
	                printf("%d\n",stack[i]);
	        }
        }
}
