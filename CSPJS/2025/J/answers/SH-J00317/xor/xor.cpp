#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e5 + 8;
int n, k, pfx[MAXN], dp[MAXN];
map<int, vector<int> > res;
vector<int> edg[MAXN];

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1, inp; i <= n; i++)
    {
        cin >> inp;
        pfx[i] = inp ^ pfx[i - 1];
        res[pfx[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j : res[k ^ pfx[i]])
        {
            if (j < i) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << dp[n];

    fclose(stdin);
    fclose(stdout);

    return 0;
}
