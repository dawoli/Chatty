#include<bits/stdc++.h>
using namespace std;
constexpr int N=100005;
int dp[N],a[N],T,n,k,len=0,nx,ni;
void solve()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        int jx=max(nx,a[i]);
        int ji=min(ni,a[i]);
        int ju=jx-ji;
        int nl=len+1;
        if (nl*k-ju>dp[i-1])
        {
            dp[i]=nl*k-ju;
            nx=jx;
            ni=ji;
            len=nl;
        }
        else dp[i]=dp[i-1];
    }
    cout<<dp[n]<<endl;
}
int main()
{
    int c;
    cin>>c>>T;
    while (T--)
    {
        len=0;
        nx=INT_MIN;
        ni=INT_MAX;
        memset(dp,0,N);
        solve();
    }
}