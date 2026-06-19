#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5008,mod=998244353;
ll a[N],dp[N];
ll Pow2(ll n){
    if(n==0)return 1;
    ll x=Pow2(n>>1);
    if(n&1)return x*x*2%mod;
    else return x*x%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n,m=0;
    cin>>n;
    for(ll i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    m=a[n];
    dp[0]=1;
    ll ansi=0,ans=0;
    for(ll i = 1;i <= n;i++){
        if(i>1){
            for(ll j = m;j >= a[i-1];j--){
                dp[j]+=dp[j-a[i-1]];
                dp[j]%=mod;
            }
        }
        ll ansi=0;
        for(ll j = 0;j <= a[i];j++)ansi=(ansi+dp[j])%mod;
        ans=(ans+Pow2(i-1)-ansi+mod)%mod;
    }
    cout<<ans;
    return 0;
}
