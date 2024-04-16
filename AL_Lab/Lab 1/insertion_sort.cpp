    #include <iostream>
    using namespace std;
    int c;
    void print(int a[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<" "<<a[i];
    }
    void insertionsort(int a[],int n)
    {
        int i,j,k;
        c++;
        for(i=1;i<n;i++)
        {
            c++;
            k=a[i];
            c++;
            for(j=i-1;j>=0 && a[j]>k;j--)
            {
                c++;
                a[j+1]=a[j];
                c++;
            }
            c++;
            a[j+1]=k;
        }
    }
    int main()
    {
        int i,j,k,n;
        cout<<"Enter the number of elements: ";
        cin>>n;
        int a[n];
        cout<<"Enter the elements: ";
        for(i=0;i<n;i++)
            cin>>a[i];
        insertionsort(a,n);
        cout<<"\nThe sorted array is: ";
        print(a,n);
        cout<<"\nThe number of steps are: "<<c<<endl;
        return 0;
    }
