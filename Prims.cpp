#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >graph[10];
int vis[100];
int par[100];
#define inf 1000
int node,edge;
int cost[100];
priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
void Prims(int src) {
    PQ.push(make_pair(0,src ));
    for(int i=0; i<=10; i++)cost[i]=inf;
    int mst = 0,prev=-1;
    cout<<"The Selected Vertices are: "<<endl;
    cout<<"\tvertex\t\tWeight"<<endl;
    cout<<"\t----------------------\n";
    while(!PQ.empty()) {
        int u = PQ.top().second;
        int cst =PQ.top().first;
        PQ.pop();
        if(vis[u]==1)continue;
        mst+=cst;
        if(prev!=-1) {
            cout<<"\t("<<prev<<" , "<<u<<") ------->"<<cst<<endl;
        }
        vis[u] =  1;
        for(int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(cost[v] >  w ) {
                cost [v] = w;
                par[v] = u;
                PQ.push( make_pair(cost[v], v));
            }
            prev=u;
        }
    }
    cout<<"Total Sum of weights are : "<<mst<<endl;
}

int main() {

    cin>>node>>edge;

    for(int i=0; i<edge; i++) {
        int x,y,w;
        cin>>x>>y>>w;

        graph[x].push_back(make_pair(y,w) );
        graph[y].push_back(make_pair(x,w) );
    }
    Prims(1);
}
/*
a b c d e f g h i
1 2 3 4 5 6 7 8 9

9 14
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
*/



