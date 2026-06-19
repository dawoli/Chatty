#include<bits/stdc++.h>
using namespace std;
const int N=5010,Mod=998244353; int a[N];
long long qpow(long long a,long long b) {
    long long ans=1;
    while(b) {
        if(b&1) ans=ans*a%Mod;
        a=a*a%Mod,b>>=1;
    }
    return ans;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,mx=0; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    if(mx<=1) {
        long long ans=qpow(2ll,n);
        ans-=n; (ans+=Mod)%=Mod;
        ans--; (ans+=Mod)%=Mod;
        long long t=1ll*n*(n-1)%Mod*qpow(2,Mod-2)%Mod;
        ans-=t; (ans+=Mod)%=Mod;
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++) {
        int sum=0,res=0,cnt=0;
        for(int j=1;j<=n;j++) if((i>>(j-1))&1) sum+=a[j],res=max(res,a[j]),cnt++;
        if(cnt>=3&&sum>2*res) ans++,ans%=Mod;
    }
    cout<<ans;
    return 0;
}
