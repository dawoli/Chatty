#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
constexpr int N=10029;
constexpr ll inf=1e18;
struct edge{
    int id,u,v,w;
};
vector<edge> e;
int n,m,k;
int p[N];
int fl(int x){
    if(p[x]==x) return x;
    return p[x]=fl(p[x]);
}

// ll ans=0;
bool ok[N];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int c[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        e.pb((edge){0,u,v,w});
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            e.pb((edge){j,j+n,i,x});
        }
    }
    sort(all(e),cmp);
    // return 0;
    int lmt=(1<<k);
    ok[0]=1;
    ll ans=inf;
    int E=e.size();
    for(int o=0;o<lmt;o++){
        ll ret=0;
        for(int i=1;i<=k;i++) ok[i]=(o>>(i-1)&1),ret+=c[i]*ok[i];
        for(int i=1;i<=n+k;i++) p[i]=i; 
        int cnt=0,ned=n+__builtin_popcount(o)-1;
        for(int i=0;i<E;i++){
            if(!ok[e[i].id]) continue;
            int u=fl(e[i].u),v=fl(e[i].v);
            if(u^v){
                p[u]=v;
                ret+=e[i].w;
                cnt++;
                if(ret>=ans) break;
                if(cnt==ned){
                    ans=ret;
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}