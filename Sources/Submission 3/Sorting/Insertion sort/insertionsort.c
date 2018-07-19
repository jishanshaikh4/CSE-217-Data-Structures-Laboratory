#include <stdio.h>

void insertion_sort(int arr[], int n);
int main(){
	int arr[500], i, n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	insertion_sort(arr, n);
	printf("\nThe sorted array is: ");
	for(i=0;i<n;i++)
	printf("\t%d", arr[i]);
	return 0;
}
void insertion_sort(int arr[], int n){
	int i, j, temp;
	for(i=1; i<n; i++){		
		temp=arr[i];		
		j=i-1;
		while((temp < arr[j])&&(j>=0)){
			arr[j+1]=arr[j];
			j--;
		}		
		arr[j+1]=temp;
	}
}
