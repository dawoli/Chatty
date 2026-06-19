#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 502424*2, maxn = 10246, maxk = 11;
struct road
{ int u, v, w, x; }
roads [maxm + maxk * maxn];
bool cmp (road& a, road& b) { return a.w < b.w; }
int fa [maxn], c [maxk], n, m, k, rcnt;
int find (int x)
{ return fa [x] == fa [fa [x]] ? fa [x] : fa [x] = find (fa [x]); }
void merge (int x, int y)
{
    int fx = find (x), fy = find (y);
    if (fx != fy) fa [fx] = fy;
}
ll solve (int mask)
{
    int i;
    for (i=1; i<maxn; i++) fa [i] = i;
    ll ans = 0; int req = n-1;
    for (i=0; i<k; i++)
    if (mask & (1<<i))
    req++, ans += c [i+1];
    int cc = 0;
    for (i=0; i<rcnt; i++)
    {
        if (cc >= req) break;
        road& cur = roads [i];
        if (cur.x && (mask & (1<<cur.x-1)) == 0) continue;
        if (find (cur.u) == find (cur.v)) continue;
        merge (cur.u, cur.v);
        cc++; ans += cur.w;
    }
    return ans;
}
int main (void)
{
    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);
    int i, j, u, v, w;
    scanf ("%d%d%d", &n, &m, &k);
    for (i=0; i<m; i++)
    {
        scanf ("%d%d%d", &u, &v, &w);
        roads [rcnt++] = {u, v, w, 0};
    }
    for (i=1; i<=k; i++)
    {
        scanf ("%d", c+i);
        for (j=1; j<=n; j++)
        {
            scanf ("%d", &w);
            roads [rcnt++] = {n+i, j, w, i};
        }
    }
    sort (roads, roads+rcnt, cmp);
    ll res = LLONG_MAX;
    for (i=0; i<(1<<k); i++)
    {
        ll r = solve (i);
        if (r < res) res = r;
    }
    printf ("%lld\n", res);
    return 0;
}
