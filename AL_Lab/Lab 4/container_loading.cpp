#include<bits/stdc++.h>
using namespace std;

void sort_weight(vector<int> w)
{
    sort(w.begin(),w.end());
}
void display(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int c,weight;
    vector<int> w;
    cout<<"Enter the maximum capacity: ";
    cin>>c;
    cout<<"Enter the weights(enter -1 to stop): ";
    for(;;)
    {
        cin>>weight;
        if(weight==-1)
            break;
        w.push_back(weight);
    }
    int n=w.size();
    sort_weight(w);
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i]=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt=cnt+w[i];
        if(cnt<=c)
        {
            v[i]=1;
            c-=w[i];
        }
    }
    display(v);
    return 0;
}

