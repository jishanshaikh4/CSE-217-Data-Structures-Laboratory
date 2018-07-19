#include <stdio.h>

void merge(int a[], int, int, int);
void sort(int a[],int, int);

int main(){
	int arr[1000], i, n;
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, 0, n-1);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
	printf(" %d\t", arr[i]);
	return 0;
}

void merge(int arr[], int low, int mid, int high){
	int i=low, j=mid+1, index=low, temp[1000], k;
	while((i<=mid) && (j<=high)){
		if(arr[i] < arr[j]){
			temp[index]=arr[i];
			i++;
		}
		else{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid){
		while(j<=high){
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else{
		while(i<=mid){
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(k=low;k<index;k++)
		arr[k]=temp[k];
}
void sort(int arr[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		sort(arr, low, mid);
		sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}
