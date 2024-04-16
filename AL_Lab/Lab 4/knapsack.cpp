#include <bits/stdc++.h>
using namespace std;
class knapsack
{
public:
    int id;
    double weight, profit, pd;
    double knap(double w, double p, double pd, int id)
    {
        weight = w;
        profit = p;
        pd = p / w;
        id = id;
        return pd;
    }
};
void sort_weight(knapsack c[], int n)
{
    int i, j;
    knapsack temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (c[j].weight > c[j + 1].weight)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}
void sort_profit(knapsack c[], int n)
{
    int i, j;
    knapsack temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (c[j].profit < c[j + 1].profit)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}
void sort_pd(knapsack c[], int n)
{
    int i, j;
    knapsack temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (c[j].pd < c[j + 1].pd)
            {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}
void knapsack_loading(knapsack c[], int cp, int nc, int x[], int y[], int z[])
{
    int p1 = 0, p2 = 0, p3 = 0;
    for (int i = 0; i < nc; i++)
    {
        x[i] = 0;
        y[i] = 0;
        z[i] = 0;
    }
    cp = 100;
    sort_weight(c, nc);
    for (int i = 0; i < nc && c[i].weight <= cp; i++)
    {
        x[c[i].id] = 1;
        cp -= c[i].weight;
        p1 += c[i].profit;
    }
    cp = 100;
    sort_profit(c, nc);
    for (int i = 0; i < nc && c[i].weight <= cp; i++)
    {
        y[c[i].id] = 1;
        cp -= c[i].weight;
        p2 += c[i].profit;
    }
    cp = 100;
    sort_pd(c, nc);
    for (int i = 0; i < nc && c[i].weight <= cp; i++)
    {
        z[c[i].id] = 1;
        cp -= c[i].weight;
        p3 += c[i].profit;
    }
    int temp = (p1 > p2) ? p1 : p2;
    int highest = (p3 > temp) ? p3 : temp;
    if (highest == p1)
    {
        cout << "Greedy criterion based on weight gives highest profit\n";
        cout << p1 << "\n";
        for (int i = 0; i < nc; i++)
            cout << x[i] << " ";
    }

    else if (highest == p2)
    {
        cout << "Greedy criterion based on profit gives highest profit\n";
        cout << p2 << "\n";
        for (int i = 0; i < nc; i++)
            cout << y[i] << " ";
    }

    else if (highest == p3)
    {
        cout << "Greedy criterion based on profit density gives the highest profit\n";
        cout << p3 << "\n";
        for (int i = 0; i < nc; i++)
            cout << z[i] << " ";
    }
}
int main()
{
    knapsack c[15];
    int nc, cp = 100;
    cout << "Enter the total number of containers: ";
    cin >> nc;
    int x[nc], y[nc], z[nc];
    for (int i = 0; i < nc; i++)
    {
        cout << "Enter the weight of container " << (i + 1) << ": ";
        cin >> c[i].weight;
        cout << "Enter the profit of container " << (i + 1) << ": ";
        cin >> c[i].profit;
        c[i].id = i;
    }
    for (int i = 0; i < nc; i++)
    {
        c[i].pd = c[i].knap(c[i].weight, c[i].profit, c[i].pd, c[i].id);
    }
    knapsack_loading(c, cp, nc, x, y, z);
    return 0;
}
