#include <bits/stdc++.h>
using namespace std;
inline int rd (void)
{
    char c = getchar (); int k = 0;
    while (c < '0' || c > '9') c = getchar ();
    while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar ();
    return k;
}
bool M [1005] [1005], r [1005] [1005];
int main (void)
{
    freopen ("explore.in", "r", stdin);
    freopen ("explore.out", "w", stdout);
    int t = rd ();
    while (t--)
    {
        int n, m, i, j, k, x, y, d;
        n = rd (); m = rd (); k = rd ();
        x = rd (); y = rd (); d = rd ();
        for (i=0; i<=n+1; i++) M [i] [0] = M [i] [m+1] = 1;
        for (i=0; i<=m+1; i++) M [0] [i] = M [n+1] [i] = 1;
        for (i=1; i<=n; i++)
        {
            char c = getchar (); while (c != '.' && c != 'x') c = getchar ();
            for (j=1; j<=m; j++) M [i] [j] = c == 'x', c = getchar ();
        }
        for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        r [i] [j] = 0;
        r [x] [y] = 1;
        for (i=0; i<k; i++)
        {
            int g=x, h=y;
            if (d == 0) h++;
            else if (d == 1) g++;
            else if (d == 2) h--;
            else if (d == 3) g--;
            if (M [g] [h]) d = (d + 1) % 4;
            else x = g, y = h;
            r [x] [y] = 1;
        }
        int cnt = 0;
        for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        if (r [i] [j]) cnt ++;
        printf ("%d\n", cnt);
    }
}
