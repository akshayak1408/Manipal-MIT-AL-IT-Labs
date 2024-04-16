#include<iostream>
using namespace std;
int n;
void transpose(int n,int source,int arr[][20])
{
    int visited[n],u,v,i;
    for(i=1;i<n+1;i++)
        visited[i]=0;
    int s[20],top=-1;
    s[++top]=source;
    visited[source]=1;
    while(top>=0)
    {
        u=s[top--];
    }
    for(v=1;v<n+1;v++)
    {
        if(arr[u][v]==1 && visited[v]==0)
        {
            visited[v]=1;
            s[++top]=v;
        }
        cout<<u<<" ";
    }
}

int main()
{
    int m;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>m;
    n=m;
    int adjmat1[20][20];
    int adjmat2[20][20];
    int i,j;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
            adjmat1[i][j]=0;
    }
    int u,v;
    cout<<"Enter the position of vertices that are adjacent: ";
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
            cin>>u>>v;
        if(u>0 && v>0)
            adjmat1[u][v]=1;
        else
            break;
        if(u<1 || v<1)
            break;
    }
    int src;
    cout<<"Enter source: "<<endl;
    cin>>src;
    cout<<"Adjacency matrix: "<<endl;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            cout<<adjmat1[i][j]<<" ";
            if(adjmat1[i][j]==0 && i!=j)
                adjmat2[i][j]=1;
            else
                adjmat2[i][j]=0;
        }
        cout<<endl;
    }
    cout<<"Transpose of adjacency matrix: "<<endl;
    for(i=1;i<n+1;i++)
        for(j=1;j<n+1;j++)
    {
        cout<<adjmat2[i][j]<<" ";
    }
    cout<<endl;
    cout<<"BFS: ";
    transpose(n,src,adjmat1);
    cout<<endl;
    cout<<"BFS of tranpose graph: ";
    transpose(n,src,adjmat2);
    cout<<endl;
    return 0;
}
