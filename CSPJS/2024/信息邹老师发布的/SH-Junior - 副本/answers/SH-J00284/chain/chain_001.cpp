#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 1e5 + 8;
int T, n, k, q, l[MAXN], s[MAXN][1005], r, c;

bool dfs(int id, int st, int rmn)
{
    if (rmn == 0)
    {
        if (st == c) return true;
        return false;
    }

    int stid;
    for (int i = 1; i <= l[id]; i++)
    {
        if (s[id][i] == st)
        {
            stid = i;
            for (int j = 1; j <= l[id]; j++)
            {
                if (j != i && abs(j - stid) <= k)
                {
                    for (int k = 1; k <= n; k++)
                    {
                        if (k != id)
                        {
                            for (int ku = 1; ku <= l[k]; ku++)
                            {
                                if (s[k][ku] == s[id][j])
                                {
                                    bool ans = dfs(k, s[k][ku], rmn) - 1;
                                    if (ans == true) return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

signed main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    cin >> T;
    while (T--)
    {
        vector<int> have[MAXN];
        cin >> n >> k >> q;

        int minlen = 2e9, maxlen = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            minlen = min(minlen, l[i]);
            maxlen = max(maxlen, l[i]);
            for (int j = 1; j <= l[i]; j++)
            {
                cin >> s[i][j];
                have[s[i][j]].push_back(i);
            }
        }

        if (minlen < k)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> r >> c;
            if (have[1].size() <= 0)
            {
                cout << 0 << endl;
                continue;
            }
            for (int pl : have[1])
            {
                bool flag = dfs(pl, 1, r);
                if (flag) cout << 1 << endl;
                else cout << 0 << endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
