#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int a[5010];

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
        {
            flag = 0;
        }
    }

    if (n < 3)
    {
        cout << 0;
    }
    else if (flag == 1)
    {
        int ans = 0;
        for (int i = 3; i <= n; i++)
        {
            int temp = 1;
            if (i != n)
            {
                for (int j = n; j >= i; j--)
                {
                    temp *= j;
                }
            }
            ans += temp;
        }
        cout << ans % 998244353;
    }
    else if (n == 3)
    {
        
        int maxn = max(a[1], max(a[2], a[3]));
        if (a[1] + a[2] + a[3] > (2 * maxn))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}