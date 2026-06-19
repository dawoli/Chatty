#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,k,ans;
int c[15][1000005];
bool vis[10005][10005];

struct node
{
    int u,v,w;
}road[1000005];

bool cmp(node x,node y)
{
    return x.w < y.w;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        cin >> road[i].u >> road[i].v >> road[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin >> c[i][j];
        }
    }
    sort(road+1,road+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(!vis[road[i].u][road[i].v])
        {
            ans += road[i].w;
            vis[road[i].u][road[i].v] = 1,vis[road[i].v][road[i].u] = 1;
        }
    }
    cout << ans;
    return 0;
}
