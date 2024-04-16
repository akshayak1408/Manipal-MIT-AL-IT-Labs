#include<iostream>
using namespace std;
int count=0;
int binarysearchrecur(int a[],int ele,int l,int h)
{
    int mid=(l+h)/2;
    count++;
    count++;
    if(l>h)
    {
        count++;
        return -1;
    }
    count++;
    if(a[mid]==ele)
    {
        count++;
        return mid;
    }
    count++;
         if(ele<a[mid])
         {
            count++;
            return binarysearchrecur(a,ele,l,mid-1);
         }
         else
         {
             count++;
            return binarysearchrecur(a,ele,mid+1,h);
         }
}
int main()
{
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to search for: ";
    int k;
    cin>>k;
    int index=binarysearchrecur(a,k,0,n-1);
    if(index==-1)
        cout<<"\nNumber not found!";
    else
        cout<<"\nElement is found at index "<<index;
    cout<<"\nThe number of steps are: "<<count;
    return 0;
}
