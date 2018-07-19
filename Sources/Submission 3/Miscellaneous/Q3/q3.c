#include<stdio.h>

int main(){
	int normstack[100], minstack[100];
	int top=-1; int dop=-1; int count=0; int CurrentMin;
	int choice; int data;
	while(1){
		printf("\n1: Push\t2: Pop\t3: Get-minimum\t4: Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter Data to Push: ");
				scanf("%d", &data);
				normstack[++top]= data;
				if(count==0){
					minstack[++dop]= data;
					CurrentMin=data;
				}
				else if(data<CurrentMin)
					CurrentMin=data;
				count++;
				break;
			case 2:
				data= normstack[top--];
				printf("\nPopped Data is %d\n",data);
				if(data==CurrentMin)
				dop--;
                                CurrentMin= minstack[dop];
				break;
			case 3:
				printf("\nCurrent Minimum Element in Stack is %d\n",CurrentMin);
	 			break;
	      		case 4:
				return 0;
		}
	}
}
