#include<stdio.h>
#include<ctype.h>
  
int stack[100];
int top=-1 ;          

void push(int item){
 if(top>=100-1){
   printf("stack overflow");
   return;
 }
 else{
  top++;
  stack[top]=item;
 }
}

int pop(){
 int item;
 if(top==-1){
  printf("stack underflow");
 }
 else{
  item=stack[top];
  top--;
  return item;
  }
}

void EvalPostfix(char postfix[]){
 int i;
 char ch;
 int val;
 int A, B ;
 for (i=0 ; postfix[i]!=')'; i++){
  ch=postfix[i];
  if (isdigit(ch)){
   push(ch - '0');
  }
  else if (ch=='+' || ch=='-' || ch=='*' || ch=='/'){
   A=pop();
   B=pop();
   switch (ch){
    case '*':
    	val=B * A;
    	break;

    case '/':
    	val=B / A;
    	break;

    case '+':
    	val=B + A;
        break;

    case '-':
	val=B - A;
	break;
    }
    push(val);
   }
  }
 printf( " \n Result of expression evaluation : %d \n", pop()) ;
}

int main(){
 int i ;
 char postfix[100];
 printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
 printf( " \nEnter postfix expression,\npress right parenthesis ')' for end expression : ");
 for (i=0 ; i<=99; i++){
  scanf("%c", &postfix[i]);
  if ( postfix[i]==')' ){ 
   break;
  } 
 }
 EvalPostfix(postfix);
 return 0;
}
