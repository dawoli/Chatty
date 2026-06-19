#include <bits/stdc++.h>
using namespace std;
const int maxn = 524;
char ss [maxn];
int s [maxn], c [maxn];
typedef long long ll;
const ll p = 998244353;
int main (void)
{
    freopen ("employ.in", "r", stdin);
    freopen ("employ.out", "w", stdout);
    int n, m; scanf ("%d%d", &n, &m);
    int i; scanf ("%s", ss);
    for (i=0; i<n; i++) s [i+1] = ss [i] - '0';
    for (i=1; i<=n; i++) scanf ("%d", c+i);
    int ssum = 0;
    for (i=1; i<=n; i++) ssum += s [i];
    if (ssum == n)
    {
        int nzc = 0;
        for (i=1; i<=n; i++)
        if (c [i] != 0)
        nzc ++;
        if (m > nzc) puts ("0");
        else
        {
            ll r = 1;
            for (i=1; i<=n; i++) r = r * i % p;
            printf ("%lld\n", r);
        }
    }
    else if (m == n) puts ("0");
}
