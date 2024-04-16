#include<bits/stdc++.h>
using namespace std;

void merged(int arr[],int s,int e)
{
    int mid = (e+s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int arr1[len1];
    int arr2[len2];

    int k=s;

    for (int i=0;i<len1;i++)
    arr1[i]=arr[k++];

    k=mid+1;
    for (int i=0;i<len2;i++)
    arr2[i]=arr[k++];

    int ind1=0;
    int ind2=0;
    int l=s;
    while (ind1<len1 && ind2<len2)
    {
        if (arr1[ind1]<arr2[ind2]){
        arr[l++]=arr1[ind1++];
        }
        else
        arr[l++]=arr2[ind2++];
    }
    while (ind1<len1)
    arr[l++]=arr1[ind1++];

    while (ind2<len2)
    arr[l++]=arr2[ind2++];
}

void mergesort(int arr[],int s,int e)
{
    if (s>=e)
    return ;
    int mid = (e+s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merged(arr,s,e);
}

int main()
{
    int arr[]={8,3,5,1,7,9,10};
    mergesort(arr,0,6);
    for (int i=0;i<7;i++)
    cout<<arr[i]<<" ";
    return 0;
}
