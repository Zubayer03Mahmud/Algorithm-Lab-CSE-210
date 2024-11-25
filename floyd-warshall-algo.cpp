// All Pair Shortest Path Algorithm
// Floyd - Warshall Algorithm
// Uses Dynamic Programming Approach
// Works when the graph has negative weighted edge and has a cycle having negative weight
// V times Graph Relaxation
// Time Complexity is O(EV) for sparse graph for best case
// Time Complexity is O(V^3) for dense graph for worst case case

// Negative weighted cycle has detected in this problem
// Floyd - Warshall Algorithm
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,e,u,v,w,f;
    vector< pair< int, pair<int,int> > > edge;
    cout<<"\tFLOYD-WARSHALL ALGORITHM\n";
    cout<<"Enter the number of vertexes and edges: ";
    cin>>n>>e;
    int dist[n+1][n+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dist[i][j]=1e9;
        }
    }
    cout<<"Enter the edges(u,v) and their respective weights(w):\n";
    for(int i=0; i<e; i++) {
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
    cout<<"\nThe given weighted adjacency matrix of the graph is:\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (dist[i][j]>=1e9) cout<<setw(5)<<"INF"<<" ";
            else cout<<setw(5)<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                 if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != 1e9 && dist[i][k] != 1e9)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout<<"The following matrix shows the shortest distances between every pair of vertexes\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if (dist[i][j]>=1e9) cout<<setw(5)<<"INF"<<" ";
            else cout<<setw(5)<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
4 6
1 2 3
1 4 5
2 1 2
2 4 4
3 2 1
4 3 2
*/





