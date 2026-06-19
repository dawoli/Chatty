#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 3e6 + 5;
int n,k,a[N],dp[N],f[N],d[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    memset(d,0x3f,sizeof(d));
    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i],a[i] ^= a[i - 1];
        int num = k ^ a[i];
        if (d[num] < N) f[i] = d[num];
        else f[i] = -1;
        d[a[i]] = i;
        dp[i] = dp[i - 1];
        if (f[i] != -1) dp[i] = max(dp[i],dp[f[i]] + 1);
        // cout << f[i] << " ";
    }
    cout << dp[n];
    return 0;
}
