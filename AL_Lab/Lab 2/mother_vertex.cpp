#include<iostream>
#include<queue>
using namespace std;

void breadth_first_search(int a[][20],int visited[],int v,int x)
{
    int w;
    queue<int> q;
    q.push(x);
    for(int i=1;i<=v;i++)
        visited[i]=0;
    visited[x]=1;
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
    }
}
/*void mother_vertex(int visited[],int v,int a[][20])
{
    for(int i=1;i<=v;i++)
    {
        breadth_first_search(a,visited,v,i);
        if(visited[i]!=i)
        {
           cout<<"There is no mother vertex!";
           break;
        }
        else
            cout<<"The mother vertex is: "<<i;
    }
}*/
void mother_vertex(int visited[],int v,int a[][20])
{
    for(int i=1;i<=v;i++)
    {
        breadth_first_search(a,visited,v,i);
        if(visited[i]!=i)
        {

           break;
        }
        else
            cout<<"The mother vertex is: "<<i;
    }
}
int main()
{
    int a[20][20],visited[20],v,e,m,n,x;
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
    for(int i=1;i<=e;i++)
    {
        cin>>m>>n;
        a[m][n]=1;
    }
    mother_vertex(visited,v,a);
    return 0;
}
