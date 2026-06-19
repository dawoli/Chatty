#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll a[15][100005],c[15];
ll f[100005],pos[100005];
ll vis[15];
struct node{
    ll u,v,w;
};
vector<node>e; 
ll find(ll x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(ll x,ll y){
    ll fx=find(x),fy=find(y);
    if(fx!=fy){
        f[fx]=fy;
    }
}
bool cmp(node x,node y){
    return x.w<y.w;
}
ll work(){
    for(ll i=1;i<=n;i++){
        f[i]=i;
    }
    sort(e.begin(),e.end(),cmp);
    ll ans=0;
    for(auto x:e){
        if(find(x.u)!=find(x.v)){
            merge(x.u,x.v);
            ans+=x.w;
        }
    }
    return ans;
}
ll fans=1e18;
void dfs(ll dep){
    if(dep==k+1){
        vector<node> v;
        v=e;
        ll cnt=0,cnt2=0;
        for(ll i=1;i<=k;i++){
            if(vis[i]){
                cnt++;
                cnt2+=c[i];
                for(ll j=1;j<=n;j++){
                    e.push_back({n+cnt,j,a[i][j]});
                }
            }
        } 
        n+=cnt;
        fans=min(fans,work()+cnt2);
        n-=cnt;
        e=v;
        return;
    }
    dfs(dep+1);
    vis[dep]=1;
    dfs(dep+1);
    vis[dep]=0;
}
map<ll,ll> mp[10005];
map<ll,bool> mp2[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        if(mp2[min(u,v)][max(u,v)])
            mp[min(u,v)][max(u,v)]=min(mp[min(u,v)][max(u,v)],w);
        else
            mp2[min(u,v)][max(u,v)]=1,mp[min(u,v)][max(u,v)]=w;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(mp2[i][j])
                e.push_back({i,j,mp[i][j]});
        }
    }
    ll flag1=1;
    for(ll j=1;j<=k;j++){
        cin>>c[j];
        if(c[j]!=0)flag1=0;
        ll t=0;
        for(ll i=1;i<=n;i++){
            cin>>a[j][i];
            if(a[j][i]==0)
                t=1;
        }
        if(t==0)flag1=0;
    }
    if(flag1==1){
        for(ll j=1;j<=k;j++){
            for(ll i=1;i<=n;i++){
                cin>>a[j][i];
                if(a[j][i]==0)
                    pos[j]=i;
            }
        }
        for(ll j=1;j<=k;j++){
            ll u=pos[j];
            for(ll i=1;i<=n;i++){
                if(i!=u){
                    e.push_back({u,i,a[j][i]});
                }
            }
        }
        cout<<work()<<endl;
        return 0;   
    }
    if(k==0){
        cout<<work()<<endl;
        return 0;
    }
    dfs(1);
    cout<<fans<<endl;
}