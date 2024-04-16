#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges: ";
    cin>>v>>e;
    vector<vector<pair<int,int>>> adjl(v);
    cout<<"Enter the edges and their weights: ";
    for (int i=0;i<e;i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjl[src].push_back(make_pair(dest,weight));
        adjl[dest].push_back(make_pair(src,weight));
    }

    vector<int> distance(v,INT_MAX);
    set<pair<int,int>> s;

    int src;
    cin>>src;

    distance[src]=0;
    s.insert(make_pair(0,src));

    while (!s.empty())
    {
        pair<int,int> least=*(s.begin());
        int nodedist = least.first;
        int node = least.second;
        s.erase(s.begin());

        for (auto x : adjl[node])
        {
            if ((nodedist+x.second)<distance[x.first])
            {
                auto remain = s.find(make_pair(distance[x.first],x.first));

                if (remain != s.end())
                s.erase(remain);

                distance[x.first]=nodedist+x.second;
                s.insert(make_pair(distance[x.first],x.first));
            }
        }
    }
    cout<<endl;
    for (int i=0;i<distance.size();i++)
    cout<<distance[i]<<" "<<i<<endl;
    return 0;
}
