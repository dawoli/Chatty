#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5,mod = 998244353;
int n,a[N],f[N],ans;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    f[min(5001ll,a[1] + a[2])]++;
    for (int i = 3; i <= n; i++)
    {
        for (int j = a[i] + 1; j <= 5001; j++) ans = (ans + f[j]) % mod;
        // for (int j = 1; j <= 15; j++) cout << f[j] << " ";
        // cout << endl;
        for (int j = 5001; j >= 1; j--) f[min(5001ll,j + a[i])] = (f[min(5001ll,j + a[i])] + f[j]) % mod;
        for (int j = 1; j < i; j++) f[min(5001ll,a[i] + a[j])] = (f[min(5001ll,a[i] + a[j])] + 1) % mod;
    }
    cout << ans;
    return 0;
}
