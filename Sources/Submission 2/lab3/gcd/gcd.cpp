#include <stdio.h>

int gcd(int a, int b);

int main(){
	int n1, n2, s;
	printf("Enter two integers: ");
	scanf("%d %d",&n1,&n2);
	s=gcd(n1, n2);
	printf("The gcd of entered two numbers is %d\n",s);
	return 0;
}

int gcd(int a, int b){
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	if(a==b)
		return a;
	else 
		return (gcd(b,a-b));
}
