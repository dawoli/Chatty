#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,m,a[6]={0,0,0,0,0,0};string s;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=8;j++)
        {
            cin>>s;
            if(s=="math") a[i]++;
        }
        a[i]+=a[i-1];
    }
    cin>>n>>m;
    n+=(m-1);
    long long ans=n/7*a[5];
    if(n%7>5) ans+=a[5];
    else ans+=a[n%7];
    if(m!=1)
    {
        if(m>5) ans-=a[5];
        else ans-=a[m-1];
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}