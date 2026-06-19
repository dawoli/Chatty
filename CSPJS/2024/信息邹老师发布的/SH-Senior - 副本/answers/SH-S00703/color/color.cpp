#include <cstdio>
#include <iostream>
using namespace std;
int t, n, a[200001];
bool l[200001];
long long ans;
long long tot()
{
    long long sum = 0;
    for (int i = 2; i <= n; i++)
    {
        int id = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            if (l[j] == l[i])
            {
                id = j;
                break;
            }
        }
        if (a[i] == a[id]) sum += a[i];
    }
    return sum;
}
void dfs(int x)
{
    if (x > n)
    {
        ans = max(ans, tot());
        return;
    }
    l[x] = 0;
    dfs(x + 1);
    l[x] = 1;
    dfs(x + 1);
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        l[0] = -1;
        dfs(1);
        cout << ans << '\n';
        ans = 0;
    }
    return 0;
}
