#include<iostream>
#include<stack>
using namespace std;

void depth_first_search(int a[][10],int visited[],int v,int x)
{
    int w,i;
    stack<int> s;
    s.push(x);
    cout<<x;
    for(int i=1;i<=v;i++)
        visited[i]=0;
    visited[x]=1;
    while(!s.empty())
    {
         w=s.top();
         s.pop();
      for(i=1;i<=v;i++)
        {
            if(visited[i]==0 && a[w][i]==1)
            {
                visited[i]=1;
                s.push(i);
                cout<<" ";
                cout<<i;
            }
        }
    }
}

int main()
{
    int x,visited[10];
    int v,e,a[10][10];
    int m,n;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the vertex to start traversing from: ";
    cin>>x;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
            a[i][j]=0;
    }
    cout<<"Enter the edges: ";
    for(int i=0;i<e;i++)
    {
        cin>>m>>n;
        a[m][n]=1;
    }
    cout<<"The adjacency matrix is: \n";
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
            cout<<" "<<a[i][j];
          cout<<"\n";
    }
    depth_first_search(a,visited,v,x);
    return 0;
}
