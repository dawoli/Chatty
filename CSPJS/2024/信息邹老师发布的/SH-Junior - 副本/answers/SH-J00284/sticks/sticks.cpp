#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, n;
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dfs(int rmn, int num)
{
    if (rmn < 0) return -1;
    if (rmn == 0) return num;

    int minans = 2e9;
    for (int i = 0; i <= 9; i++)
    {
        if (num == 0 && i == 0) continue;
        int ans = dfs(rmn - sticks[i], num * 10 + i);
        if (ans != -1) minans = min(minans, ans);
    }
    if (minans == 2e9) return -1;
    return minans;
}

signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> T;
    while (T--)
    {
        cin >> n;
        int finans = dfs(n, 0);
        if (finans == -1) cout << -1 << endl;
        else cout << finans << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
