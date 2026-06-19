#include <bits/stdc++.h>
using namespace std;
pair <int, int> zone (int V, int L, int d, int v, int a)
{
    if (a == 0)
    {
        if (v > V) return {d, L+1};
        else return {0, 0};
    }
    if (a > 0)
    {
        if (v > V) return {d, L+1};
        else return {(V * V - v * v) / (a * 2) + d + 1, L+1};
    }
    if (v <= V) return {0, 0};
    int dv = V * V - v * v;
    if (dv % (2 * a) == 0) return {d, d + dv / a / 2 - 1};
    else return {d, d + dv / a / 2};
}
pair <int, int> zs [100050]; int ps [1000050], pp [1000050], zc;
bool cmp (pair <int, int>& a, pair <int, int>& b)
{
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
int main (void)
{
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    int t; scanf ("%d", &t);
    while (t--)
    {
        int n, m, L, V, i, d, v, a, c;
        scanf ("%d%d%d%d", &n, &m, &L, &V);
        for (i=0; i<n; i++)
        {
            scanf ("%d%d%d", &d, &v, &a); d++;
            auto z = zs [i] = zone (V, L, d, v, a);
        }
        for (i=0; i<=L; i++) ps [i] = pp [i] = 0;
        for (i=0; i<m; i++)
        {
            scanf ("%d", &d); d++;
            ps [d] = 1;
        }
        for (i=1; i<=L+5; i++) pp [i] = ps [i] + pp [i-1];
        zc = c = 0;
        for (i=0; i<n; i++)
        {
            auto z = zs [i];
            if (z.second > L + 1) z.second = L + 1;
            if (z.second == 0 || z.first > L + 1 || pp [z.second] == pp [z.first-1]) continue;
            else zs [zc++] = z;
        }
        printf ("%d ", zc);
        if (zc == 0)
        {
            printf ("%d\n", m);
            continue;
        }
        sort (zs, zs+zc, cmp); c = 1;
        for (i=0; i+1<zc; i++)
        {
            auto z = zs [i];
            auto y = zs [i+1];
            if (y.second <= z.second) continue;
            if (pp [z.second] <= pp [y.first-1]) c++;
            else zs [i+1] .second = z.second;
        }
        printf ("%d\n", m-c);
    }
    return 0;
}
