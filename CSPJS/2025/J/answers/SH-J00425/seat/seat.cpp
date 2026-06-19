#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N * N], n, m, xiaoA, cnt;
signed main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    xiaoA = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                cnt++;
                if (a[cnt] == xiaoA)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                cnt++;
                if (a[cnt] == xiaoA)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
}
// AC
