#include <bits/stdc++.h>
using namespace std;
int ct, k;
int st[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool f;
void dfs(int id, int num, int mn, int ans)
{
    if (f)
        return;
    if (id > k)
    {
        if (num == ct)
            cout << ans, f = 1;
        return;
    }
    if (id != 1)
        dfs(id + 1, num + st[0], 0, ans * 10);
    for (int i = 1; i < 10; i++)
        dfs(id + 1, num + st[i], i, ans * 10 + i);
}
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        f = 0;
        int n;
        cin >> n;
        if (n < 2)
        {
            cout << -1 << endl;
            continue;
        }
        int num = ceil(n / 7.0) - 6;
        k = min(6, (int)ceil(n / 7.0) - max(0, num));
        ct = n - max(0, int(ceil(n / 7.0) - 6) * 7);
        dfs(1, 0, 1, 0);
        for (int i = 1; i <= num; i++)
            cout << 8;
        cout << endl;
    }
    return 0;
}