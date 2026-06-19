#include <algorithm>
#include <iostream>
using namespace std;
pair<int, int> r[100000];
int p[100000];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, m, l, vm, d, v, a, ans, k, tp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> l >> vm;
        for (int i = 0; i < n; i++)
        {
            cin >> d >> v >> a;
            r[i] = a > 0 ? make_pair(v > vm ? d : (vm * vm - v * v) / (2 * a) + d + 1, l) : a < 0 ? make_pair(d, v <= vm ? -1 : (v * v - vm * vm - 1) / (-2 * a) + d)
                                                                                                  : make_pair(d, v > vm ? l : -1);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> p[i];
        }
        k = 0;
        for (int i = 0; i < n; i++)
        {
            if (r[i].first > r[i].second)
            {
                continue;
            }
            int le = 0, ri = m - 1, mid;
            while (le <= ri)
            {
                mid = (le + ri) / 2;
                if (r[i].first > p[mid])
                {
                    le = mid + 1;
                }
                else
                {
                    ri = mid - 1;
                }
            }
            r[k].first = le;
            le = 0;
            ri = m - 1;
            while (le <= ri)
            {
                mid = (le + ri) / 2;
                if (r[i].second < p[mid])
                {
                    ri = mid - 1;
                }
                else
                {
                    le = mid + 1;
                }
            }
            r[k].second = ri;
            if (r[k].first <= r[k].second)
            {
                k++;
            }
        }
        sort(r, r + k);
        tp = m;
        ans = k != 0;
        for (int i = 0; i < k; i++)
        {
            if (r[i].first > tp)
            {
                tp = r[i].second;
                ans++;
            }
            else
            {
                tp = min(tp, r[i].second);
            }
        }
        cout << k << ' ' << m - ans << endl;
    }
    return 0;
}