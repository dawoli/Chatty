#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll a[100005],inv[100005],f[100005];
ll n;
ll C(ll m,ll k){
    if(m==k)return 1;
    return f[m]*inv[k]%mod*(inv[n-k])%mod;
}
ll ans;
void dfs(ll dep,ll s,ll mx,ll cnt){
    if(dep==n+1){
        if(s>2*mx&&cnt>=3)
            ans++;
        ans%=mod;
        return;
    }
    dfs(dep+1,s+a[dep],max(mx,a[dep]),cnt+1);
    dfs(dep+1,s,mx,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    ll mx=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    f[1]=1,inv[1]=1;
    for(ll i=2;i<=n;i++){
        f[i]=f[i-1]*i;
        f[i]%=mod;
    }
    for(ll i=2;i<=n;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    for(ll i=2;i<=n;i++){
        inv[i]=inv[i-1]*inv[i]%mod;
    }
    if(mx==1){
        ll ans=0;
        for(ll i=3;i<=n;i++){
            ans+=C(n,i);
            ans%=mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans<<endl;
}