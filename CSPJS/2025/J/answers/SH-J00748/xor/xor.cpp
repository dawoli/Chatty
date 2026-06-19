#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],s[500005];
ll f[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    cin>>n>>k;
    map<ll,ll> mp;
    mp[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(ll i=1;i<=n;i++){
        f[i]=max(f[i],f[i-1]);
        ll t=s[i]^k;
        if(t==0){
            f[i]=max(f[i],1ll);
        }
        if(mp[t]!=0){
            f[i]=max(f[i],f[mp[t]]+1);
        }
        mp[s[i]]=i;
    }
    cout<<f[n]<<endl;
}