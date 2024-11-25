#include<bits/stdc++.h>
using namespace std;
#define inf 1000

vector<pair<int,int> >graph[10];
int par[100];
int node,edge;
int cost[100];
priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>PQ;

void Dijkstra(int src) {
    for(int i=1; i<=node; i++)cost[i]=inf;
    cost[src]=0;
    PQ.push(make_pair(0,src ));
    while(!PQ.empty()) {
        int u = PQ.top().second;
        PQ.pop();
        for(int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(cost[v] > cost[u] + w ) {
                cost [v] = cost[u] + w;
                par[v] = u;
                PQ.push( make_pair(cost[u] + w, v));
            }

        }
    }
    cout<<"Vertex\tMin cost   Parent"<<endl;
    for(int i=1; i<=5; i++)cout<<"   "<<i<<" \t   "<<cost[i]<<" \t\t"<<par[i]<<endl;
}

int main() {
    cout<<"Enter no of node and edges : ";
    cin>>node>>edge;
    for(int i=0; i<edge; i++) {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w) );
    }
    Dijkstra(1);
}
/*
5 9
 1 2 7
 1 4 2
 2 4 2
 4 2 3
 2 3 1
 4 3 8
 4 5 5
 3 5 4
 5 3 5

*/



