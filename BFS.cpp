#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

queue<int>q;
int n,e;
map<int,int>vis;

vi bfs(int src,const vi g[])
{
    vi dis(n+1);
    for(int i=1; i<=n; i++)dis[i]=1000;

    dis[src]=0;
    vis[src]=1;
    q.push(src);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v:g[x])
        {
            if(!vis[v])
            {
                dis[v]=1+dis[x];
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return dis;
}


int main()
{

    cout<<"Enter no of Vertices and Edges : ";
    cin>>n>>e;

    int source;
    vi g[n+1],dis(n+1);   /// 1 based Indexing

    cout<<"Enter edges :"<<endl;
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout<<"Enter Source : ";
    cin>>source;
    dis= bfs(source,g);

    for(int i=1; i<=n; i++)

        cout<<"Distance from "<<(char)(source+'A'-1)<<" To "<<(char)(i+'A'-1)<<" is : "<<dis[i]<<endl;

    return 0;
}


