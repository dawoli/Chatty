#include <cmath>
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t, n, m, l, v, ans1, ans2, p[100001];
bool f;
priority_queue <int> qp;
struct node{int d, v, a;}x[100001];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> l >> v;
        for (int i = 1; i <= n; i++) cin >> x[i].d >> x[i].v >> x[i].a;
        for (int i = 1; i <= m; i++) cin >> p[i];
        for (int i = 1; i <= n; i++)
        {
            if (x[i].a < 0)
            {
                int nxt = p[lower_bound(p + 1, p + m + 1, x[i].d) - p];
                int mx = ceil(sqrt(x[i].v * x[i].v * 1.0 + 2.0 * x[i].a * (nxt - x[i].d)));
                if (mx > v && x[i].d <= p[m])
                {
                    ++ans1;
                    qp.push(nxt);
                }
            }
            else if (x[i].a == 0)
            {
                if (x[i].v > v && x[i].d <= p[m])
                {
                    ++ans1;
                    if (f == 0)
                    {
                        ++ans2;
                        f = 1;
                    }
                }
            }
            else
            {
                int mx = ceil(sqrt(x[i].v * x[i].v * 1.0 + 2.0 * x[i].a * (p[m] - x[i].d)));
                if (mx > v && x[i].d <= p[m])
                {
                    ++ans1;
                    if (f == 0)
                    {
                        ++ans2;
                        f = 1;
                    }
                }
            }
        }
        while (!qp.empty())
        {
            int u = qp.top();
            qp.pop();
            while (!qp.empty() && qp.top() == u) qp.pop();
            ++ans2;
        }
        cout << ans1 << ' ' << m - ans2 << '\n';
        f = ans1 = ans2 = 0;
     }
    return 0;
}
