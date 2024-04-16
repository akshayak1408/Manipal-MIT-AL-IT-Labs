#include <iostream>
using namespace std;
int count;
int search(int arr[], int n, int x)
{
 int i;
 count++;
 for (i = 0; i < n; i++)
 {
 count++;
 count++;
 if (arr[i] == x)
 {
 count++;
 return i;
 }
 }
 count++;
 count++;
 if(i==n)
 {
     count++;
     return -1;
 }

}
int main(void)
{
 int arr[25], n, x;
 count=0;
 cout<<"enter no. of elements ";
 cin>>n;
 cout<<"enter "<< n <<" elements";
 for(int i=0;i<n;i++)
 cin>>arr[i];
 cout<<"enter the element to be searched ";
 cin>> x;
 int result = search(arr, n, x);
 (result == -1)? cout<<"Element is not present in array"
 : cout<<"Element is present at index " <<result;
 cout<<endl;
 cout<<"Number of steps for search function "<<count;
 return 0;
}
