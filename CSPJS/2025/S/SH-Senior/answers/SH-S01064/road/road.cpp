#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL; 
const ll N=1e4+9,E=1e6+13,K=12;
struct Edge{
    ll to,nxt,w;
}e[E*2];
ll hd[N],nE;
ll ok[N],dis[N];
ll n,m,k,c[K],a[N][K];
void addEdge(ll u,ll v,ll w){
    e[++nE]=(Edge){v,hd[u],w};
    hd[u]=nE;
}
ll prim(){
    priority_queue<PLL,vector<PLL>,greater<PLL> > q;
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    ll ans=0;
    q.push({dis[1],1});
    while(!q.empty()){
        ll u=q.top().second;
        q.pop();
        if(ok[u])continue;
        ok[u]=1;
        ans+=dis[u];
        for(ll i = hd[u];i;i=e[i].nxt){
            ll v=e[i].to;
            if(dis[v]>e[i].w){
                dis[v]=e[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll flag=1;
    cin>>n>>m>>k;
    for(ll i = 1;i <= m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    for(ll i = 1;i <= k;i++){
        cin>>c[i];
        if(c[i])flag=0;
        for(ll j = 1;j <= m;j++){
            cin>>a[i][j];
            if(a[i][j])flag=0;
        }
    }
    if(flag && k>0){
        cout<<0;
    }
    else if(k==0){
        cout<<prim();
    }
    return 0;
}
