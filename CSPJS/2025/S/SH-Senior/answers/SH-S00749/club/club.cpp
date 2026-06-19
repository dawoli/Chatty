#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
pair<ll,ll> a[100005][3];
ll deltamx[1000005];
ll f[205][205][205];
ll pos[100005];
ll A[100005],b[100005],c[100005];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.first>y.first;
}
bool cmp2(ll x,ll y){
    return deltamx[x]>deltamx[y];
}
ll cnt[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=200){
            for(ll i=1;i<=n;i++){
                cin>>A[i]>>b[i]>>c[i];
            }
            ll ans=0;  
            memset(f,0,sizeof(f));
            for(ll i=1;i<=n;i++){
                for(ll j=0;j<=min(i,n/2);j++){
                    for(ll k=0;k<=min(i-j,n/2);k++){
                        if(i-j-k>n/2)continue;
                        if(j>0)
                            f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+b[i]);
                        if(k>0)
                            f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+c[i]);
                        if(i-j-k>0)
                            f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+A[i]);
                        ans=max(ans,f[i][j][k]);
                    }
                }
            } 
            cout<<ans<<endl;
            continue;
        }
        for(ll i=1;i<=n;i++){
            cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
            a[i][1].second=1,a[i][2].second=2,a[i][3].second=3;
            sort(a[i]+1,a[i]+4,cmp);
            deltamx[i]=a[i][1].first-a[i][2].first;
            pos[i]=i;
        }
        sort(pos+1,pos+n+1,cmp2);
        memset(cnt,0,sizeof(cnt));
        ll ans=0;
        for(ll i=1;i<=n;i++){
            if(cnt[a[pos[i]][1].second]<n/2){
                cnt[a[pos[i]][1].second]++;
                ans+=a[pos[i]][1].first;
            }else{
                cnt[a[pos[i]][2].second]++;
                ans+=a[pos[i]][2].first;
            }
        }
        cout<<ans<<endl;
    }
}