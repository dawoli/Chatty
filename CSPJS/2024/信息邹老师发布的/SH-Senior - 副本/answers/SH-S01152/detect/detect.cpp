#include <bits/stdc++.h>
using namespace std;
int T;
int d[100005], v[100005], a[100005], p[100005];
bool used[100005];
pair<int, int> need[100005];
unordered_set<int> chaoed;
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        chaoed.clear();
        memset(need, 0, sizeof need);
        int n, m, L, V;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &p[i]);
        sort(p + 1, p + m);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > 0)
            {
                double s = (1.0 * V * V - v[i] * v[i]) / (2 * a[i]); // 正好超速
                int l, r;
                for (int j = 1; j <= m; ++j)
                {
                    if (d[i] + s < p[j])
                    {
                        l = j;
                        chaoed.insert(i);
                        used[j] = 1;
                        break;
                    }
                }
                for (int j = l; j <= m; ++j)
                {
                    if (d[i] + s >= p[j] && d[i] <= p[j])
                    {
                        r = j - 1;
                        break;
                    }
                }
                need[i] = {l, r};
            }
            else if (a[i] == 0)
            {
                if (v[i] > V)
                {
                    for (int j = 1; j <= m; ++j)
                    {
                        if (p[j] >= d[i])
                        {
                            chaoed.insert(i);
                            used[j] = 1;
                            need[i] = {j, m};
                            break;
                        }
                    }
                }
            }
            else
            {
                if (v[i] > V)
                {
                    double s = (1.0 * V * V - v[i] * v[i]) / (2 * a[i]); // 正好卡速
                    int l, r;
                    for (int j = 1; j <= m; ++j)
                    {
                        if (d[i] + s > p[j] && d[i] <= p[j])
                        {
                            l = j;
                            used[j] = 1;
                            chaoed.insert(i);
                            break;
                        }
                    }
                    for (int j = l; j <= m; ++j)
                    {
                        if (d[i] + s <= p[j])
                        {
                            r = j - 1;
                            break;
                        }
                    }
                    need[i] = {l, r};
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            if (!used[i])
                ++ans;
        }
        printf("%d %d\n", chaoed.size(), ans);
    }
    return 0;
}
