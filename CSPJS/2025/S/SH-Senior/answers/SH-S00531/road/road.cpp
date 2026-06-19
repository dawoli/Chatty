#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 10010, M = 1100010;
struct edge { ll a, b, c; }s[M], s1[N*10], s2[M];
bool cmp(edge x, edge y) { return x.c < y.c; }
ll n, m, k, p[N], fa[N], a[12][N];
ll find(ll x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }
ll kruskal(ll n1, ll tot) // points total, edges total
{
    for (ll i = 1; i <= n1; i++) fa[p[i]] = p[i];
    ll ret = 0, cnt = 0;
    for (ll i = 1; i <= tot; i++)
    {
        ll fx = find(s2[i].a), fy = find(s2[i].b);
        if (fx != fy) fa[fx] = fy, ret += s2[i].c, cnt++;
        if (cnt == n1-1) break;
    } return ret;
}
void solve()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (ll i = 1; i <= m; i++) scanf("%lld%lld%lld", &s[i].a, &s[i].b, &s[i].c);
    sort(s + 1, s + m + 1, cmp);
    ll flag = 1;
    for (ll i = 1; i <= k; i++)
    {
        scanf("%lld", &a[i][0]), flag &= (!a[i][0]);
        ll f = 0;
        for (ll j = 1; j <= n; j++) scanf("%lld", &a[i][j]), f |= (!a[i][j]);
        flag &= f;
    }
    if (!k)
    {
        for (ll i = 1; i <= m; i++) s2[i] = s[i];
        for (ll i = 1; i <= n; i++) p[i] = i;
        printf("%lld\n", kruskal(n, m)); return ;
    }
    if (flag)
    {
        for (ll i = 1; i <= n+k; i++) p[i] = i;
        ll tots1 = 0;
        for (ll i = 1; i <= k; i++)
            for (ll j = 1; j <= n; j++) s1[++tots1] = {n+i, j, a[i][j]};
        sort(s1 + 1, s1 + tots1 + 1, cmp);
        ll i = 1, j = 1, tot = 0;
        while (i < m && j < tots1)
            if (s[i].c <= s1[j].c) s2[++tot] = s[i++];
            else s2[++tot] = s1[j++];
        while (i < m) s2[++tot] = s[i++];
        while (j < tots1) s2[++tot] = s1[j++];
        printf("%lld\n", kruskal(n+k, tot));
        return ;
    }
    if (k <= 5)
    {
        ll mi = (ll)1e18;
        for (ll i = 1; i <= n; i++) p[i] = i;
        for (ll i = 0; i < (1LL<<k); i++)
        {
            ll tmp = 0, n1 = n;
            for (ll j = 0; j < k; j++)
                if ((i>>j)&1) tmp += a[j+1][0], p[++n1] = j+1;
            ll tots1 = 0;
            for (ll j = 1; j <= k; j++) if ((i>>(j-1))&1)
                for (ll l = 1; l <= n; l++) s1[++tots1] = {n+j, l, a[j][l]};
            sort(s1 + 1, s1 + tots1 + 1, cmp);
            ll i1 = 1, j1 = 1, tot = 0;
            while (i1 < m && j1 < tots1)
                if (s[i1].c <= s1[j1].c) s2[++tot] = s[i1++];
                else s2[++tot] = s1[j1++];
            while (i1 < m) s2[++tot] = s[i1++];
            while (j1 < tots1) s2[++tot] = s1[j1++];
            tmp += kruskal(n1, tot), mi = min(mi, tmp);
        } printf("%lld\n", mi);
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
