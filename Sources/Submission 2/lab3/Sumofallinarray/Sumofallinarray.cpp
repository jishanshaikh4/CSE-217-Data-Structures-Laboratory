#include<stdio.h>
 
int findSum(int A[], int n){
    if (n<=0)
        return 0;
    return (findSum(A, n-1)+A[n-1]);
}

int main(){
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
  	  scanf("%d",&A[i]);
    printf("The sum of all the elements of array is %d\n", findSum(A, n));
    return 0;
}
