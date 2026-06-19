#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
struct Node
{
    int cha, l, r;
    bool operator<(const Node &x) const
    {
        if (cha == x.cha) return l > x.l;
        else return cha > x.cha;
    }
};
int a[N], b[N], f[N], vis[N], n, k, mark[N];
priority_queue<Node> pq;
void solve1()
{
    if (k == 0)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 0) cnt++;
        cout << cnt << "\n";
    }
    else
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) cnt++;
        cout << cnt << "\n";
    }
}
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    cin >> n >> k;
    bool flag = false, flag1 = false;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
        if (a[i] != 1) flag = true;
        if (a[i] > 1) flag1 = true;
    }
    // xor[l, r] = xor[l - 1] ^ xor[r]
    if (k == 0 && !flag)
    {
        cout << n / 2 << "\n";
    }
    else if (!flag1 && (k == 1 || k == 0))
    {
        solve1();
    }
    else
    {
        for (int l = 1; l <= n; l++)
        {
            for (int r = l; r <= n; r++)
            {
                if ((b[l - 1] ^ b[r]) == k) f[l] = min(f[l], r), vis[l] = true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pq.push({f[i] - i, i, f[i]});
        }
        int cnt = 0;
        while (!pq.empty())
        {
            Node fr = pq.top();
            pq.pop();
            bool flag = true;
            int j;
            for (int i = fr.l; i <= fr.r; i++)
            {
                mark[i]++;
                if (mark[i] > 1)
                {
                    flag = false, j = i;
                    break;
                }
            }
            if (flag) cnt++;
            else
            {
                for (int i = fr.l; i <= j; i++) mark[i]--;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
