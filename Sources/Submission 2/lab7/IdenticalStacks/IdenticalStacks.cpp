#include<stdio.h>
#include<iostream>
#include<stdlib.h>

class stack
{
	public:
	int arr[100];
	int top;
	int start , full ;
	int valid;
        public:
	stack(){
         top = start = -1;  
         full = 100 ;  
	 valid = 1;  
	}
        void push(int a);
	int pop();
};

void stack::push(int a)
{
 if(top == full-1 ){
  printf("\n the stack is full cannot enter any more values");
 }
 else{
  top++ ;
  arr[top] = a ;
 }
}

int stack::pop(){
 int i;
 if(top == start)
 {
  printf("\n the stack is empty");
  printf("\n A garbage value is printed");
  valid = 0;
 }
 else
 {
  i = arr[top];
  top--;
  valid = 1;
 }
 if(valid == 1)
 {
  return i;
 }
}
int main()
{
	stack s;
	char c , i ;
	int flag = 1 , count = 0;
 	printf("\nEnter the number of elements : ");
	printf("\nEnter the elements : ");
	while(1)
	{
  	fflush(stdin);
	printf("\nenter :");
	scanf("%c",&c);

		if( c=='('|| c== '{'|| c== '[')
		{
		  s.push(c);
		  count++;  
		}
                if( c== ')'|| c== '}' || c==']')
		{
		 i = s.pop();
		 count--;
		 switch(c)
			{
			 case ')':
				if( i == '(')
					flag = 1;   
				else
					flag = 0;
				break;
			case '}':
				if( i == '{')
					flag = 1;
				else
					flag = 0;
				break;
			case ']':
				if( i == '[')
					flag = 1;
				else
					flag = 0;
				break;
			}


		}
		if( flag == 0 || c == 'y')
		 break;
               }
       if( flag == 0 || count != 0)
		printf(" not a valid string");
       else
		printf(" a valid string");

       return 0;
}

