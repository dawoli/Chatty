#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;

int s[510];
int c[510];

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    bool a = true;
    int first = -1;
    for (int i = 1;i <= n;i++)
    {
        char c;
        cin >> c;
        s[i] = c - '0';
        if (s[i] == 0)
        {
            a = false;
        }
        else
        {
            if (first == -1)
            {
                first = i;
            }
        }
    }
    int cnt = 0;
    int n2 = n;
    for (int i = 1;i <= n;i++)
    {
        cin >> c[i];
        if (c[i] >= first)
        {
            cnt++;
        }
        if (c[i] == 0)
        {
            n2--;
        }
    }
    if (!a)
    {
        if (m == 1)
        {
            int ans = cnt;
            for (int i = 1;i <= n2 - 1;i++)
            {
                ans *= i;
                ans %= mod;
            }
            cout << ans << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    else
    {
        if (n2 < m)
        {
            cout << 0 << endl;
            return 0;
        }
        int ans = 1;
        for (int i = 1;i <= n2;i++)
        {
            ans *= i;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }
    return 0;
}
