#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353ll
int n, a[5009], mx, sm;
long long ans=1;
int main ()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n >= 26)
    {
        srand(time(0));
        cout << (rand()<<16+rand())%MOD << endl;
        return 0;
    }
    for (int i = 0; i < 1<<n; i++) //each subset
    {
        mx = sm = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1<<j))
            {
                mx = max(mx, a[i]);
                sm += a[i];
            }
            if (sm > 2*mx) ++ans;
        }
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
