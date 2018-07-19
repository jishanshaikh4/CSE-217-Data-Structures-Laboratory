#include <stdio.h>

int largest(int arr[], int n);
void radix_sort(int arr[], int n);

int main(){
	int arr[1000], i, n;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	radix_sort(arr, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);
	return 0;
}
int largest(int arr[], int n){
	int large=arr[0], i;
	for(i=1;i<n;i++){
		if(arr[i]>large)		
			large=arr[i];
	}
	return large;
}
void radix_sort(int arr[], int n){
	int bucket[1000][1000], bucket_count[1000];
	int i, j, k, remainder, NOP=0, divisor=1, large, pass;
	large=largest(arr, n);
	while(large>0){		
		NOP++;	
		large/=1000;
	}
	for(pass=0;pass<NOP;pass++){		
		for(i=0;i<1000;i++)
			bucket_count[i]=0;
		for(i=0;i<n;i++){			
			remainder=(arr[i]/divisor)%1000;
			bucket[remainder][bucket_count[remainder]]=arr[i];		
			bucket_count[remainder] += 1;
		}
		i=0;
		for(k=0;k<1000;k++){			
			for(j=0;j<bucket_count[k];j++){
				arr[i]=bucket[k][j];	
				i++;
			}
		}
		divisor *= 1000;
	}
}
