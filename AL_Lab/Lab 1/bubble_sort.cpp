#include<iostream>
using namespace std;
int ct=0;
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       cout<<a[i]<<" ";
    }
}
 void bubblesort(int a[],int n)
{
 int i,j,temp;
 ct++;
   for(i=0;i<n;i++)
    {    ct++;
      for(j=i+1;j<n;j++)
        {    ct++;
             ct++;
            if(a[j]<a[i])
            {
                ct++;
                temp=a[i];
                ct++;
                a[i]=a[j];
                ct++;
                a[j]=temp;
            }
        }
    }
 }
int main()
{
    int i, j,n,temp;
    int a[20];
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    bubblesort(a,n);
    cout<<"The sorted array is: ";
    print(a,n);
    cout<<"\nThe number of steps are: "<<ct;
    return 0;
}
