#include <bits/stdc++.h>

using namespace std;

bool seted[10]={};
long c[10]={};
long a[10][10000]={};

struct edge
{
    long to,cost;
};

struct vertex
{
    bool done=0,setup,cost=LONG_MAX;
    std::vector<edge> edges;
    std::vector<long> village;
};

std::vector<vertex> graph;

int main()
{
    long n,m,k,i,j,u,v,w,now=0;
    cin>>n>>m>>k;
    graph.resize(n)
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        graph[u].edges.push_back({v,w});
        graph[v].edges.push_back({u,w});
    }
    for(i=0;i<k;i++)
    {
        cin>>c[i];
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    while()
    {

    }
    return(0);
}
