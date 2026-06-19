#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,all,no,ans;
const ll k=100003;
ll qpow(ll x,ll y)
{
    if (y==0)return 1%k;
    ll sum=1;
    while (y)
    {
        if (y&1)sum=sum*x%k;
        x=x*x%k;
        y>>=1;
    }
    return sum;
}
int main()
{
    cin>>m>>n;
    all=qpow(m,n);
    no=m%k*qpow(m-1,n-1)%k;
    ans=all-no;
    if (ans<0)ans+=k;
    cout<<ans<<endl;
    return 0;
}