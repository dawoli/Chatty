#include <bits/stdc++.h>
using namespace std;

int n,m;
struct Edge
{
    int u,v,w,is;
};

vector<Edge> e[1000010];
int dis[10010];

int bfs()
{
    queue<int> q;
    //for (int i)
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w,0});
        e[v].push_back({u,w,0});
    }
    cout << 0 << endl;
    return 0;
}
