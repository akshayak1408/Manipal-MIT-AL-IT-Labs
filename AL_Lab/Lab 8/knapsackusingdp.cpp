#include<bits/stdc++.h>
using namespace std;

int Max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int wt[20];
    int p[20];
    int m,n;
    cout<<"Enter the number of weights: ";
    cin>>n;
    cout<<"Enter the maximum capacity: ";
    cin>>m;
    cout<<"Enter the weights and their profits: ";
    wt[0]=0;
    p[0]=0;
    for(int i=1;i<=n;i++)
        cin>>wt[i]>>p[i];
    int k[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=m;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
                k[i][w]=Max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    cout<<k[n][m]<<endl;
    int i=n,j=m;
    while(i>0 || j>0)
    {
        if(k[i][j]==k[i-1][j])
        {
            cout<<wt[i]<<" = 0"<<endl;
            i--;
        }
        else
        {
            cout<<wt[i]<<" = 1"<<endl;
            j=j-wt[i];
            i--;
        }
    }
    return 0;
}
