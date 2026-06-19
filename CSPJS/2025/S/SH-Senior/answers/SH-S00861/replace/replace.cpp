#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
constexpr int N=1000009;
int n,q;
set<pair<ll,ll> >tb;
const ll mod=1e9+7;
ll hsh(string x){
    ll ret=0,pw=1;
    for(int i=0;i<x.size();i++){
        ret+=1ll*pw*(x[i]-'a'+1)%mod;
        pw*=131ll;
        ret%=mod; pw%=mod;
    }
    return ret;
}
ll hshx[N],hshy[N],ipw[N],pw[N];
ll xhsh(ll l,ll r){
    return 1ll*(hshx[r]-hshx[l-1]+mod)%mod*ipw[l-1]%mod;
}
ll yhsh(ll l,ll r){
    return 1ll*(hshy[r]-hshy[l-1]+mod)%mod*ipw[l-1]%mod;
}
int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y&1) ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ans;
}
string strx[N],stry[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    bool ok=1;
    for(int i=1;i<=n;i++){
        // string x,y;
        cin>>strx[i]>>stry[i];
        for(auto o:strx[i]) if(o!='a'&&o!='b') ok=0;
        for(auto o:stry[i]) if(o!='a'&&o!='b') ok=0;
        tb.insert(mkp(hsh(strx[i]),hsh(stry[i])));
    }
    pw[0]=ipw[0]=1;
    for(int i=1;i<=3000;i++) pw[i]=1ll*pw[i-1]*131ll%mod;
    int inv=qpow(131,mod-2);
    for(int i=1;i<=3000;i++) ipw[i]=1ll*ipw[i-1]*inv%mod;
    for(int i=1;i<=q;i++){
        string x,y;
        cin>>x>>y;
        int len=x.size();
        x=" "+x;
        y=" "+y;
        ll ret=0;
        for(int i=1;i<=len;i++){
            ret+=1ll*pw[i-1]*(x[i]-'a'+1)%mod;
            ret%=mod;
            hshx[i]=ret;
        }
        ret=0;
        for(int i=1;i<=len;i++){
            ret+=1ll*pw[i-1]*(y[i]-'a'+1)%mod;
            ret%=mod;
            hshy[i]=ret;
        }
        ll ans=0;
        for(int j=1;j<=len;j++){
            for(int k=j;k<=len;k++){
                if(xhsh(1,j-1)==yhsh(1,j-1)&&xhsh(j,k)!=yhsh(j,k)&&xhsh(k+1,len)==yhsh(k+1,len)){
                    if(tb.count(mkp(xhsh(j,k),yhsh(j,k)))) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}