#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,p,k;
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
    cin>>b>>p>>k;
    cout<<b<<'^'<<p<<" mod "<<k<<'='<<qpow(b,p)<<endl;
    return 0;
}