#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long t, n, m, week, ans, day[6];
string s;
int main()
{
    freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> s;
                if (s == "math") ++day[i];
            }
            week +=  day[i];
        }
        cin >> n >> m;
        n -= (7 - m + 1);
        for (int i = m; i <= 5; i++)
            ans += day[i];
        ans += week * (n / 7);
        n %= 7;
        for (int i = 1; i <= min(n, 5ll); i++)
            ans += day[i];
        cout << ans << '\n';
        ans = week = 0;
        memset(day, 0, sizeof(day));
    }
    return 0;
}
