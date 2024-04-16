#include<bits/stdc++.h>
using namespace std;

#define V 6

int minvertex(vector<int>& value, vector<bool>& setMST)
{
    int Min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    {
        if(setMST[i]==false && value[i]<Min)
        {
            vertex=i;
            Min=value[i];
        }
    }
    return vertex;
}

void findmst(int graph[V][V])
{
    int parent[V];
    vector<bool> setMST(V,false);
    vector<int> value(V,INT_MAX);
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<V-1;i++)
    {
        int U=minvertex(value,setMST);
        setMST[U]=true;
        for(int j=0;j<V;j++)
        {
            if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j])
            {
                value[j]=graph[U][j];
                parent[j]=U;
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        cout<<"U->V: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<endl;
    }
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
    findmst(graph);
    return 0;
}
