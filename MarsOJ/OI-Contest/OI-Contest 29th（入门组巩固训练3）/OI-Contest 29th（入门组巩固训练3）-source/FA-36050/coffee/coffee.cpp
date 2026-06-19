#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
int T;
void solve()
{
    long long ans=0;
    int n,m,a[8]={0};
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=8;j++)
        {
            string x;
            cin>>x;
            if(x=="math")a[i]++;
        }
    }
    int sum=a[1]+a[2]+a[3]+a[4]+a[5];
    s(n);s(m);
    if(m==7)n--;
    if(m==6)n-=2;
    if(m==5)
    {ans+=a[5];n-=3;}
    if(m==4)
    {ans+=(a[5]+a[4]);n-=4;}
    if(m==3)
    {ans+=(a[5]+a[4]+a[3]);n-=5;}
    if(m==2)
    {ans+=(a[5]+a[4]+a[3]+a[2]);n-=6;}
    ans+=(sum*(n/7));
    n=n%7;
    for(int i=1;i<=n;i++)ans+=a[i];
    cout<<ans<<'\n';
}
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    s(T);
    while(T--)
        solve();
    return 0;
}
