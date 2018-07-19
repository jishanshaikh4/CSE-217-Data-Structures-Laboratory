#include <stdio.h>

int partition(int a[], int low, int high);
void quick_sort(int a[], int low, int high);

int main(){
	int arr[1000], i, n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n-1);
	printf("\nThe sorted array is:\t");
	for(i=0;i<n;i++)
		printf("%d \t", arr[i]);
	return 0;
}
int partition(int a[], int low, int high){
	int left, right, temp, loc, flag;
	loc=left=low;
	right=high;
	flag=0;
	while(flag != 1){		
		while((a[loc] <= a[right]) && (loc!=right))
			right--;
		if(loc==right)
			flag =1;
		else if(a[loc]>a[right]){
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}		
		if(flag!=1){			
			while((a[loc] >= a[left]) && (loc!=left))		
				left++;
			if(loc==left)
				flag =1;
			else if(a[loc] <a[left]){
				temp=a[loc];
				a[loc]=a[left];
				a[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}
void quick_sort(int a[], int low, int high){
	int loc;
	if(low<high){
		loc=partition(a, low, high);	
		quick_sort(a, low, loc-1);
		quick_sort(a, loc+1, high);
	}
}