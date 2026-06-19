#include <iostream>
using namespace std;
using ll = long long;
ll a[200000], n;
ll f(int i, int j, int x)
{
    int ti = i == -1 || a[i] != a[x] ? 0 : a[x];
    int tj = j == -1 || a[j] != a[x] ? 0 : a[x];
    if (x == n)
    {
        return max(ti, tj);
    }
    return max(ti + f(x, j, x + 1), tj + f(i, x, x + 1));
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << f(-1, -1, 0) << endl;
    }
    return 0;
}