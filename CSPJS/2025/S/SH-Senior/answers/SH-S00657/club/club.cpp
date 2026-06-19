#include <bits/stdc++.h>
using namespace std;
const int maxn = 108432;
int a [3] [maxn], ch [maxn];
#define Max(a,b,c) (max(max((a),(b)),(c)))
inline int sec (int i)
{
    int d, e, f;
    d = a [0] [i];
    e = a [1] [i];
    f = a [2] [i];
    int x = max (max (d, e), f);
    int y = min (min (d, e), f);
    return d + e + f - x - y;
}
inline int sech (int j)
{
    int x, n, y, m; y = 0; m = 1e9+7;
    int i;
    for (i=0; i<3; i++)
    {
        int h = a [i] [j];
        if (h > y) y=h, x=i;
        if (h < m) m=h, n=i;
    }
    return 3 - x - n;
}
bool cmp (int x, int y)
{
    return
        a [ch [x]] [x] - sec (x) <
        a [ch [y]] [y] - sec (y);
}
int solve (void)
{
    int n; scanf ("%d", &n);
    int i, j, cnt [3];
    cnt [0] = cnt [1] = cnt [2] = 0;
    for (i=1; i<=n; i++)
    {
        scanf ("%d%d%d", a [0] + i, a [1] + i, a [2] + i);
        int m = Max (a [0] [i], a [1] [i], a [2] [i]);
        int c;
        for (j=0; j<3; j++)
        if (m == a [j] [i])
        c = j;
        ch [i] = c;
        cnt [c] ++;
    }
    i = 0; int m = 0;
    for (j=0; j<3; j++)
    if (cnt [j] > m)
    m = cnt [j], i = j;
    j = i;
    vector <int> li; li.reserve (n);
    for (i=1; i<=n; i++)
    if (ch [i] == j)
    li.push_back (i);
    sort (li.begin (), li.end (), cmp);
    int rst = m - n/2;
    for (i=0; i<rst; i++)
    ch [li [i]] = sech (li [i]);
    int ans = 0;
    for (i=1; i<=n; i++) ans += a [ch [i]] [i];
    return ans;
}
int main (void)
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int T; scanf ("%d", &T);
    while (T--)
    printf ("%d\n", solve ());
    return 0;
}
