#include<bits/stdc++.h>
using namespace std;
vector<int>G[2][20];
int strt[20];
int fin[20];
int tim;
vector<pair<int,int>>tmp;
map<string,int>M;
string str[20];
int componentcount;
vector<int>components[10];

void dfs(int idx, int u) {
    strt[u]=++tim;
    for(int i=0; i<G[idx][u].size(); i++) {
        int v = G[idx][u][i];
        if(strt[v]==0)
            dfs(idx, v);
    }
    fin[u]=++tim;
    if(idx==1) {
        components[componentcount].push_back(u);
    }
}
int main() {
    int n,e;
    cin>>n>>e;
    int cnt=0;
    int x,y;
    for(int i=0; i<e; i++) {
        string a,b;
        cin>>a>>b;
        if(M.find(a) == M.end() ) {
            M[a]=++cnt;
            str[cnt]=a;
        }
        x = M[a];
        if(M.find(b)==M.end() ) {
            M[b]=++cnt;
            str[cnt]=b;
        }
        y = M[b];

        G[0][x].push_back(y);
        G[1][y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(strt[i]==0) dfs(0, i);

    for(int i=1; i<=n; i++) {
        cout<<"For "<<str[i]<<"th node, start time = "<<strt[i]<<" and finish time = "<<fin[i]<<endl;
        pair<int,int> p = make_pair(fin[i],i);
        tmp.push_back(p);
    }

    sort(tmp.begin(),tmp.end());
    reverse(tmp.begin(),tmp.end());
    memset(strt,0,sizeof strt);
    memset(fin,0,sizeof fin);
    tim=0;

    for(int i=0; i<tmp.size(); i++) {
        int x = tmp[i].second;
        if(strt[x]==0) {
            componentcount++;
            dfs(1,x);
        }
    }
    cout<<"Total Number of Components = "<<componentcount<<endl;

    for(int i=1; i<=componentcount; i++) {
        cout<<"Component "<<i<<" Has "<<components[i].size()<<" nodes and they are: ";
        for(int j=0; j<components[i].size(); j++) {
            cout<<str[components[i][j]]<<" ";
        }
        cout<<endl;
    }
}
/*
8 14
A C
B A
B D
C D
C E
C B
D F
E F
E G
F D
F H
G E
G H
H H

*/



