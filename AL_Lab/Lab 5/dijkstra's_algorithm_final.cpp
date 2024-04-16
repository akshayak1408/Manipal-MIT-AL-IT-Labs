#include<bits/stdc++.h>
using namespace std;

#define V 6

int minvertex(vector<int>& value, vector<bool>& processed)
{
    int Min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(processed[i]==false && value[i]<Min)
        {
            vertex=i;
            Min=value[i];
        }
    }
    return vertex;
}
void dijkstra(int graph[V][V])
{
    vector<bool> processed(V,false);
    vector<int> value(V,INT_MAX);
    int parent[V];
    parent[V]=-1;
    value[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int U=minvertex(value,processed);
        processed[U]=true;
        for(int j=0;j<V;j++)
        {
            if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j]<value[j]))
            {
                value[j]=value[U]+graph[U][j];
                parent[j]=U;
            }
        }
    }

    for(int i=1;i<V;i++)
        cout<<"U->V: "<<parent[i]<<"->"<<i<<" wt ="<<graph[parent[i]][i]<<endl;
    /*for(int i=1;i<V;i++)
    {
        cout<<"0 -> "<<i<<" wt = "<<value[i]<<endl;
    }*/
}

int main()
{
    int graph[V][V];
    int src,dest,weight,e;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges and their weights: ";
    for(int i=0;i<e;i++)
    {
        cin>>src>>dest>>weight;
        graph[src][dest]=weight;
    }
    dijkstra(graph);
    return 0;
}
