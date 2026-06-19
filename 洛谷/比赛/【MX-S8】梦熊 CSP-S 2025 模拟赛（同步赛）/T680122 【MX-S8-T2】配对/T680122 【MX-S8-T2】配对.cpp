#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=INT_MAX;
vector<vector<int>> e;
vector<vector<int>> dis;
vector<uint8_t> c;
void dfs(int cnt)
{
    bool no0=true;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (i==j)continue;
            if (c[i]==1&&c[j]==1)
            {
                c[i]=false;
                c[j]=false;
                no0=false;
                dfs(cnt+dis[i][j]);
                c[i]=true;
                c[j]=true;
            }
        }
    }
    if (no0)
    {
        ans=min(ans,cnt);
    }
}
signed main()
{
    cin>>n;
    dis.resize(n+1,vector<int>(n+1,INT_MAX));
    e.resize(n+1,vector<int>(0));
    c.resize(n+1);
    for (int i=1;i<=n;i++)
    {
        bool a;
        cin>>a;
        c[i]=a;
    }
    for (int i=1;i<=n-1;i++)
    {
        int u,v,nw;
        cin>>u>>v>>nw;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        dis[u][v]=nw;
        dis[v][u]=nw;
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j)continue;
            swap(c[i],c[j]);
            dfs(0);
            swap(c[i],c[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}