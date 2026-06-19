#include <bits/stdc++.h>
using namespace std;

vector<int> g[10010];
vector<int> d[10010];
int a[20][1000010];
bool vis[10010];
int l[10010];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u].push_back(w);
        d[v].push_back(w);
    }
    for (int i = 1;i <= k;i++)
    {
        int c;
        cin >> c;
        int u;
        for (int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                u = j;
            }
        }
        for (int v = 1;v <= n;v++)
        {
            if (v == u)
            {
                continue;
            }
            g[u].push_back(v);
            g[v].push_back(u);
            d[u].push_back(a[i][v]);
            d[v].push_back(a[i][v]);
        }
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    long long ans = 0;
    memset(l,0x3f,sizeof(l));
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int minn = 0x3f3f3f3f - 1;
        int minx = -1;
        for (int i = 0;i < g[u].size();i++)
        {
            l[i] = min(l[i],d[u][i]);
            if (l[i] < minn && !vis[i])
            {
                minx = i;
                minn = l[i];
            }
        }
        if (minx == -1)
        {
            continue;
        }
        vis[minx] = true;
        ans += minn;
        q.push(minx);
    }
    cout << ans << endl;
    return 0;
}
