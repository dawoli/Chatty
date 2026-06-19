#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,number;
bool check(long long x)
{
    int y=x,s=0,m=0;
    long long sum=0;
    while (y)
    {
        if (y&1)
            s++;
        y>>=1;
    }
    if (s<3)
        return 0;
    y=x;
    int t=0;
    while (y)
    {
        if (y&1)
        {
            sum+=a[t+1];
            m=max(m,a[t+1]);
        }
        y>>=1;
        t++;
    }
    return (sum>2*m)?1:0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (long long i=7;i<=(1<<n);i++)
    {
        if (check(i))
        {
            ans++;
            ans%=998244353;
        }
    }
    cout<<ans;
    return 0;
}
