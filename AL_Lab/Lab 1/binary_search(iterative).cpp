#include<iostream>
using namespace std;
int ct=0;
void bnary_search(int arr[],int n,int num)
{
    int mid,l=0,h=n-1;
    ct++;
    mid=(l+h)/2;
    ct++;
    ct++;
    while(l<=h)
    {
        ct++;
        if(arr[mid]>num)
        {
            l=mid+1;
            mid=(l+h)/2;
            ct++;
            ct++;
        }
        else if(arr[mid]<num)
        {
            h=mid-1;
            mid=(l+h)/2;
            ct++;
            ct++;
        }
        else
        {
            ct++;
            return;
        }
    }
}

int main()
{
    int arr[20],num,n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to search for: ";
    cin>>num;
    bnary_search(arr,n,num);
    cout<<"The number of steps are: "<<ct;
    return 0;
}
