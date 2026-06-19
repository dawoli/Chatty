#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n, k;
int a[500010];

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    
    cin >> n >> k;
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1)
        {
            flag = 0;
        }
    }
    if (k == 0)
    {
        int cnt_one = 0;
        int cnt_zero = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                cnt_zero++;
            }
            else if (a[i] == 1)
            {
            cnt_one++;
            }
        }
        cout << cnt_zero / 2 + cnt_one / 2;
    }
    else if (k == 1)
    {
        int cnt_one = 0;
        int cnt_zero = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                cnt_zero++;
            }
            else if (a[i] == 1)
            {
                cnt_one++;
            }
        }
        cout << min(cnt_zero, cnt_one);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}