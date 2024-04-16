#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>v>>e;
    vector<vector<pair<int,int>>> adjl(v+1);
    cout<<"Enter the edges and their weights: ";
    for (int i=1;i<=e;i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjl[src].push_back(make_pair(dest,weight));
        adjl[dest].push_back(make_pair(src,weight));
    }

    vector<int> distance(v+1,INT_MAX);
    vector<bool> selected(v+1,false);
    vector<int> parent(v+1,-1);

    distance[1]=0;
    parent[1]=-1;

    for (int i=1;i<v+1;i++)
    {
        int mini=INT_MAX;
        int node;

        for (int j=1;j<v+1;j++)
        {
            if (!selected[j] && distance[j]<mini)
            {
                node=j;
                mini=distance[j];
            }
        }

        selected[node]=true;
        for (auto x : adjl[node])
        {
            int d = x.first;
            int w = x.second;
            if (!selected[d] && w<distance[d])
            {
                parent[d] = node;
                distance[d] = w;
            }
        }
    }

    for (int i=1;i<v+1;i++)
    {
        cout<<parent[i]<<" -> "<<"("<<i<<","<<distance[i]<<")"<<endl;
    }
    return 0;
}
