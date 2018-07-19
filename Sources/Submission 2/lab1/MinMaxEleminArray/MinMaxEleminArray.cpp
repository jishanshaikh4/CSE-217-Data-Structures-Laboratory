#include<iostream>
using namespace std;

int main()
{
 int max=0, min, n;
 cout<<"Enter the number of elements: ";
 cin>>n;
 int arr[n];
 cout<<"Enter elements of array:";
 for(int i=0; i<n; i++)
   cin>>arr[i];
 max=arr[0];
 for(int j=1; j<n; j++){
  if(arr[j]>max)
   {
    max= arr[j];
   }
 }
 min= arr[0];
 for(int k=1; k<n; k++)
 {
   if(arr[k]<min)
    	min= arr[k];
 }
 cout<<"Maximum element in array is :"<<max<<endl;
 cout<<"Minimum element in array is :"<<min<<endl;
 return(0);
}
