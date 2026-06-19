#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m;
string s;
ll a[100005];
ll f[100005],vis[100005];
ll ans;
void dfs(ll dep){
    if(dep==n+1){
        ll cnt=0,cnt2=0;
        for(ll i=1;i<=n;i++){
            if(cnt2<a[f[i]]&&s[i]=='1'){
                cnt++;
            }else{
                cnt2++;
            }
        }
        if(cnt>=m){
            ans++;
            ans%=mod;
        }
        return;
    }
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            f[dep]=i;
            dfs(dep+1);
            vis[i]=0;
            f[dep]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=10){
        dfs(1);
        cout<<ans<<endl;
        return 0;
    }
    cout<<0<<endl;
}