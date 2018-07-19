#include <iostream>
using namespace std;

int main()
{
 int n;
 cout<<"Enter number of elements in array: ";
 cin>>n;
 int arr[n],temp;
 cout<<"Enter elements of array:"<<endl;
 for(int i=0; i<n; i++)
  cin>>arr[i];
 for(int j=0; j<n; j++)
  {
   for(int k=j; k<n-1; k++)
    {
     if(arr[k+1]<arr[k])
     {
       temp= arr[k+1];
       arr[k+1]= arr[k];
       arr[k]= temp;
     }
    }
   }
 cout<<"\nSORTED ARRAY IS: ";
 for(int l=0; l<n; l++)
  {
   cout<<endl<<arr[l]<<" ";
  } 
  if(n%2!=0)
  {
    cout<<"\nMEDIAN IS: "<<arr[n/2]<<endl;
  }
  else
  {
    int b=n/2;
    int c=n/2+1;
    cout<<"\nMEDIAN IS: "<<(arr[b-1]+arr[c-1])/2<<endl;
  }
 return 0;  
}


