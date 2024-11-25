#include<bits/stdc++.h>
using namespace std;

vector<int>G[20];
int strt[20];
int fin[20];
int tim;

void dfs(int u)
{
    strt[u]=++tim;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(strt[v]==0)
            dfs(v);
    }
    fin[u]=++tim;
}


int main()
{
    int n,e;
    cout<<"Enter no of Vertices and Edges : ";
    cin>>n>>e;
    cout<<"Enter edges :"<<endl;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }

    dfs(1);

    for(int i=1; i<=n; i++)
    {
        cout<<"For "<<i<<"th node, start time = "<<strt[i]<<" and finish time = "<<fin[i]<<endl;
    }

}



