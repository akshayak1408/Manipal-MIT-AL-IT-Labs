#include<iostream>
#include<queue>
using namespace std;

bool cycle(int a[][20],int visited[],int v,int source,int destination)
{
    int w;
    queue<int> q;
    q.push(source);
    for(int i=1;i<=v;i++)
        visited[i]=0;
    int c=0;
    while(!q.empty())
    {
        w=q.front();
        q.pop();
        for(int i=1;i<=v;i++)
        {
            if(visited[i]==0 && a[w][i]==1)
            {
                visited[i]=1;
                q.push(i);
            }
        }
        if(c!=0)
           if(w==destination)
            return true;
            c++;
    }
        return false;
}
int main()
{
    int a[20][20],visited[20],v,e,m,n;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
            a[i][j]=0;
    }
    cout<<"Enter the edges: ";
    for(int i=1;i<=e;i++)
    {
        cin>>m>>n;
        a[m][n]=1;
    }
    int source,destination;
    cout<<"Enter the source and destination: ";
    cin>>source>>destination;
    cout<<"Cycle exists for: ";
    for(int i=1;i<=v;i++)
    {
        if(cycle(a,visited,v,i,i))
        cout<<i<<endl;
    }
    return 0;
}
