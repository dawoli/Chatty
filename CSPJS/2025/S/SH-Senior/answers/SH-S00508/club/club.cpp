#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T, n, m, a0, a1, a2, ans;
    vector<int> v[3];
    cin >> T;
    while (T--)
    {
        ans = 0;
        v[0].clear();
        v[1].clear();
        v[2].clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a0 >> a1 >> a2;
            m = 0;
            if (a0 < a1)
            {
                m = 1;
                swap(a0, a1);
            }
            if (a2 > a0)
            {
                m = 2;
                a1 = a0;
                a0 = a2;
            }
            else if (a2 > a1)
            {
                a1 = a2;
            }
            v[m].push_back(a0 - a1);
            ans += a0;
        }
        for (int i = 0; i < 3; i++)
        {
            if (v[i].size() > n / 2)
            {
                sort(v[i].begin(), v[i].end());
                ans -= accumulate(v[i].begin(), v[i].end() - n / 2, 0);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}