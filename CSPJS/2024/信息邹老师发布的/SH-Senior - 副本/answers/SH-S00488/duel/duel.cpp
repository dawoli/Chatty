#include <iostream>
using namespace std;
int t[100001];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, m = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m = max(m, a);
        t[a]++;
    }
    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, t[i]);
    }
    cout << ans;
    return 0;
}