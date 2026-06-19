#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;
using tiii = tuple<int, int, int>;
using pii = pair<int, int>;
constexpr int MAXN = 10000, MAXM = 1000000, MAXK = 10;
vector<tiii> dp[1 << MAXK];
int fa[MAXN + MAXK + 1], sz[MAXN + MAXK + 1], c[MAXK], b[1 << MAXK];
pii a[MAXK][MAXN + 1];
ll sum[1 << MAXK];
tiii rd[MAXM];
inline int read()
{
    int res = 0;
    char c;
    do
    {
        c = getchar();
    } while ('0' > c || c > '9');
    while ('0' <= c && c <= '9')
    {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}
inline void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
}
int fd(int a)
{
    return fa[a] == a ? a : fa[a] = fd(fa[a]);
}
void mg(int a, int b)
{
    a = fd(a);
    b = fd(b);
    if (a == b)
    {
        return;
    }
    if (sz[a] < sz[b])
    {
        swap(a, b);
    }
    fa[b] = a;
    sz[a] += sz[b];
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, u, v, w;
    ll ans = 0, res;
    n = read();
    m = read();
    k = read();
    for (int i = 0; i < m; i++)
    {
        u = read();
        v = read();
        w = read();
        rd[i] = make_tuple(w, u, v);
    }
    sort(rd, rd + m);
    reset(n);
    for (int i = 0; i < m; i++)
    {
        tie(w, u, v) = rd[i];
        if (fd(u) != fd(v))
        {
            dp[0].push_back(rd[i]);
            ans += w;
            mg(u, v);
        }
    }
    for (int i = 0; i < k; i++)
    {
        c[i] = read();
        for (int j = 1; j <= n; j++)
        {
            a[i][j].first = read();
            a[i][j].second = j;
        }
        sort(a[i] + 1, a[i] + n + 1);
    }
    for (int i = 0; i < 1 << (k - 1); i++)
    {
        for (int j = b[i]; j < k; j++)
        {
            reset(n + k);
            res = 0;
            int t = 1;
            for (tiii x : dp[i])
            {
                tie(w, u, v) = x;
                for (; t <= n && a[j][t].first < w; t++)
                {
                    if (fd(a[j][t].second) != fd(n + 1 + j))
                    {
                        dp[i | (1 << j)].push_back(make_tuple(a[j][t].first, a[j][t].second, n + 1 + j));
                        res += a[j][t].first;
                        mg(a[j][t].second, n + 1 + j);
                    }
                }
                if (fd(u) != fd(v))
                {
                    dp[i | (1 << j)].push_back(x);
                    res += w;
                    mg(u, v);
                }
            }
            for (; t <= n; t++)
            {
                if (fd(a[j][t].second) != fd(n + 1 + j))
                {
                    dp[i | (1 << j)].push_back(make_tuple(a[j][t].first, a[j][t].second, n + 1 + j));
                    res += a[j][t].first;
                    mg(a[j][t].second, n + 1 + j);
                }
            }
            sum[i | (1 << j)] = sum[i] + c[j];
            b[i | (1 << j)] = j + 1;
            ans = min(ans, res + sum[i | (1 << j)]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}