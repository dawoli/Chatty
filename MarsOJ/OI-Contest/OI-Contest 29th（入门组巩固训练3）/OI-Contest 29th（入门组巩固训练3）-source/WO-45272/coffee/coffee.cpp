#include <bits/stdc++.h>
using namespace std;

string a[10][10];
int s[10];

int main()
{
    freopen("coffee.in", "r", stdin);
    freopen("coffee.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        memset(s, 0, sizeof s);
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 8; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == "math") s[i]++;
            }

        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= 5; i++)
            s[i] = s[i - 1] + s[i];
        int x = n / 7;
        long long ans = x * s[5];
        int y = n % 7;
        ans = ans + s[m + y - 1];
        cout << ans << endl;
    }
    return 0;
}