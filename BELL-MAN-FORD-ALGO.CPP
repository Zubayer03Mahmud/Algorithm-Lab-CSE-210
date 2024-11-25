// Single Source Shortest Path Algorithm
// Bellman - Ford Algorithm
// Uses Dynamic Programming Approach
// Works when the graph has negative weighted edge
// Fails when the graph has a cycle having negative weight
// Maximum V-1 times Graph Relaxation
// Time Complexity is O(EV) for sparse graph for best case
// Time Complexity is O(V^3) for dense graph for worst case case

// Negative weighted cycle has not detected in this problem
// Bellman - Ford Algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,u,v,w,f;
    vector< pair< int, pair<int,int> > > edge;
    cout<<"BELLMAN-FORD ALGORITHM\n";
    cout<<"Enter the number of vertexes and edges: ";
    cin>>n>>e;
    int dist[n+1];
    for(int i=1; i<=n; i++) {
        dist[i]=1e9;
    }
    cout<<"Enter the edges(u,v) and their respective weights(w):\n";
    for(int i=0; i<e; i++) {
        cin>>u>>v>>w;
        edge.push_back({u,{v,w}});
    }
    dist[1]=0;
    for(int i=0; i<n-1; i++) {
        f=0;
        for(int j=0; j<e; j++) {
            u=edge[j].first;
            v=edge[j].second.first;
            w=edge[j].second.second;

            if(dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                f=1;
            }
        }
        if(!f) break;
    }
    cout<<"\nDistance from Source vertex 1\n";
    for(int i=1; i<=n; i++) cout<<"dist["<<i<<"] = "<<dist[i]<<endl;
}
/*
5 9
1 2 4
1 3 2
2 3 3
3 2 1
2 5 3
2 4 2
3 5 5
3 4 4
5 4 -5
*/



