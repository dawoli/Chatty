#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> e,f;
bitset<6005> vis,is_h;
int n;
void dfs(int k)
{
    vis[k]=true;
    for (int i=0;i<e[k].size();i++)
    {
        if (vis[e[k][i]])continue;
        dfs(e[k][i]);
        f[k][1]+=f[e[k][i]][0];
        f[k][0]+=max(f[e[k][i]][1],f[e[k][i]][0]);
    }
}
int main()
{
    cin>>n;
    f.resize(n+1,vector<int>(2,0));
    e.resize(n+1,vector<int>(0,0));
    for (int i=1;i<=n;i++)
    {
        cin>>f[i][1];
    }
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[y].push_back(x);
        is_h[x]=true;
    }
    for (int i=1;i<=n;i++)
    {
        if (!is_h[i])
        {
            dfs(i);
            cout<<max(f[i][0],f[i][1]);
            return 0;
        }
    }
}