#include<bits/stdc++.h>
using namespace std;

vector<int>G[20];
int strt[20];
int fin[20];
int tim;
vector<int>ans;

void dfs(int u)
{
    strt[u]=++tim;
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if(strt[v]==0)
            dfs(v);
    }
    fin[u]=++tim;
    ans.push_back(u);
}
int main() {
    int n,e;
    cout<<"No of node and edges : ";
    cin>>n>>e;
    for(int i=0; i<e; i++) {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }
    for(int i=1; i<=n; i++)
        if(strt[i] == 0) dfs(i);

    for(int i=1; i<=n; i++) {
        cout<<"For "<<i<<"th node, start time = "<<strt[i]<<" and finish time = "<<fin[i]<<endl;
    }
    cout<<"\nTopological Ordering :";
    for(int i=((int)ans.size())-1; i>=0; i--) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
/*
9 9
1 3
1 4
2 4
3 4
3 5
5 9
6 5
6 8
8 9

*/


