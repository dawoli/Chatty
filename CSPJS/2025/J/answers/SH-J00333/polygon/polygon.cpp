#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll ans = 0, aans = 0;
int n, a[5010], m;
bool vis[5010];

// jiayou
// map<set<int>, int> mem;

void dfs(int d, int maxA, int sum, int last)
{
    if (d == m)
    {
        if (sum > 2 * maxA)
        {
            ans = (ans + 1) % MOD;
        }
        return;
    }
    for (int i = last + 1; i <= n; i ++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(d + 1, max(maxA, a[i]), sum + a[i], i);
            vis[i] = 0;
        }
    }
}

map<set<int>, int> mem;

int dfs2(int d, int maxA, int sum, int last, set<int> st)
{
    if (mem[st])
    {
        return mem[st];
    }
    if (d == m)
    {
        ans = 0;
        if (sum > 2 * maxA)
        {
            ans = 1;
        }
        return mem[st] = ans;
    }
    for (int i = last + 1; i <= n; i ++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            st.insert(i);
            mem[st] = (mem[st] + dfs2(d + 1, max(maxA, a[i]), sum + a[i], i, st)) % MOD;
            st.erase(i);
            vis[i] = 0;
        }
    }
    return mem[st];
}



int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    // for (m = 3; m <= n; m ++)
    // {
    //     set<int> s;
    //     dfs(0, 0, 0, 0);
    //     // cout << ans << endl;
    //     aans = (aans + ans) % MOD;
    //     ans = 0;
    // }
    // for (m = 3; m <= n; m ++)
    // {
    //     set<int> s;
    //     ans = dfs2(0, 0, 0, 0, s);
    //     // cout << ans << endl;
    //     aans = (aans + ans) % MOD;
    //     ans = 0;
    //     mem.clear();
    // }
    for (m = 3; m <= n; m ++)
    {
        dfs(0, 0, 0, 0);
        // cout << ans << endl;
        aans = (aans + ans) % MOD;
        ans = 0;
    }
    cout << aans << endl;
    return 0;
}