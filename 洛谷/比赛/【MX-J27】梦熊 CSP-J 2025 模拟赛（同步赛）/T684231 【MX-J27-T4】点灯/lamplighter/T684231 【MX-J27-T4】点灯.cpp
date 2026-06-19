#include<bits/stdc++.h>
#define to first
#define p second
using namespace std;
int T, n, m, o, li;

void solve()
{
    int ti = clock(), d = 1;
    vector<vector<pair<int, int>>> e(n + 1, vector<pair<int, int>>(0));
    bitset<25005> b;
    bitset<25005> check;
    for (int i = 1; i <= n; i++)
    {
        check.flip(i);
    }
    queue<pair<int, int>> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    b[1] = true;
    q.emplace(1, 1);
    while (!q.empty())
    {
        int u = q.front().to;
        d = q.front().p;
        q.pop();
        if (b == check)
        {
            cout << d * o << endl;
            return;
        }
        if (clock() - li <= 10)
        {
            cout << -1 << endl;
            return;
        }
        b[u] = false;
        for (auto& i : e[u])
        {
            if (i.p > d)
            {
                continue;
            }
            q.emplace(i.to, d + 1);
            b[i.to] = true;
        }
    }
    if (b == check)
    {
        cout << d * o << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int c;
    cin >> c >> T;
    li = 2000 / T;
    while (T--)
    {
        cin >> n >> m >> o;
        solve();
    }
    return 0;
}
