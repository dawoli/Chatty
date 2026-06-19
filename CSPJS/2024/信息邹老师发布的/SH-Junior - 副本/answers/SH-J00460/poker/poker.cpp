#include <bits/stdc++.h>
using namespace std;
int a[5][14];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int a1, b1;
        if (s[0] == 'D')
            a1 = 1;
        if (s[0] == 'C')
            a1 = 2;
        if (s[0] == 'H')
            a1 = 3;
        if (s[0] == 'S')
            a1 = 4;
        if (s[1] == 'A')
            b1 = 1;
        else if (s[1] == 'T')
            b1 = 10;
        else if (s[1] == 'J')
            b1 = 11;
        else if (s[1] == 'Q')
            b1 = 12;
        else if (s[1] == 'K')
            b1 = 13;
        else
            b1 = s[1] - '0';
        a[a1][b1]++;
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 13; j++)
            if (a[i][j] == 0)
                ans++;
    }
    cout << ans;
    return 0;
}
