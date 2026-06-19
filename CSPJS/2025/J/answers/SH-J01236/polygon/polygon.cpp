#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,a[5005],dp[5005][5005],num[5005][5005],cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    sort(a+1,a+n+1);
    if(cnt>2*a[n])
        cout<<1;
    else
        cout<<0;
    return 0;
}
