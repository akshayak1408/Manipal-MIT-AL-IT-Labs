#include<bits/stdc++.h>
using namespace std;
int n=6;

void indegree(int n,int i,int adjmat[20][20],int ind[])
{
    for (int j=0;j<n;j++)
    {
        if (adjmat[j][i])
            ind[i]++;
    }
}

vector<int> topological_sort(queue<int> q,int ind[],int adjmat[20][20])
{
    vector<int> a;
    while (!q.empty())
    {
        int h=q.front();
        q.pop();
        a.push_back(h);
        for (int i=0;i<n;i++)
        {
            if (adjmat[h][i]==1)
            {
                ind[i]--;
                if (ind[i]==0)
                q.push(i);
            }
        }
    }
    return a;
}

int main()
{
    int adjmat[20][20]={0};
    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;
    int source,destination;
    cout<<"Enter the edges: ";
    for (int i=0;i<e;i++)
    {
        cin>>source>>destination;
        adjmat[source][destination]=1;
    }
    int ind[n]={0};
    queue<int> q;
    for (int i=0;i<n;i++)
    {
        indegree(n,i,adjmat,ind);
        if (ind[i]==0)
            q.push(i);
    }
    vector<int> a=topological_sort(q,ind,adjmat);

    cout<<"Graph after topological sorting is: ";
    for (int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    return 0;
}
