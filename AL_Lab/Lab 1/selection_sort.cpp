#include <iostream>
using namespace std;
int c=0;
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void selectionsort(int a[],int n)
{
    int i,j,small,s;
    c++;
    for(i=0;i<n-1;i++)
    {
        s=i;
        c++;
        small=a[i];
        c++;
        c++;
        for(j=i+1;j<n;j++)
        {
            c++;
            c++;
            if(small>a[j])
            {
                small=a[j];
                c++;
                s=j;
                c++;
            }
        }
        a[s]=a[i];
        c++;
        a[i]=small;
        c++;
    }
}
int main()
{
    int i,j,s,sm,n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    selectionsort(a,n);
    cout<<"\nThe sorted array is: ";
    print(a,n);
    cout<<"\nThe number of steps are: "<<c<<endl;
    return 0;
}
