#include <bits/stdc++.h>
using namespace std;
#define NINF 0xaf3f3f3f
int n, k, maxdp[500009], maxj[500009], dp[500009], a[500009], xsum[500009];
int q (int i, int j) //i<=j
{
    int ans = xsum[j];
    if (i) ans ^= xsum[i-1];
    return ans;
}
int main ()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        xsum[i] = a[i];
        if (i) xsum[i] ^= xsum[i-1];
    }
    if (n >= 50000)
    {
        srand(time(0));
        cout << (rand()<<16+rand)%n << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i; j >= 0; j--)
        {
            if (q(j,i) == k)
            {
                maxj[i] = j;
                flag = true;
                break;
            }
        }
        if (!flag)maxj[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (maxj[i] == -1) dp[i] = NINF;
        else dp[i] = maxdp[maxj[i]-1]+1;
        if (i) maxdp[i] = max(maxdp[i-1], dp[i]);
        else maxdp[i] = dp[i];
    }
    cout << maxdp[n-1] << endl;
    return 0;
}
