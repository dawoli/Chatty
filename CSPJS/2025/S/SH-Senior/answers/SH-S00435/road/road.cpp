#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn=4e6+9;
const ll INF=4e18;
int n,m,k;
struct Node{
    int v,w;
    bool operator >(const Node &other) const{
        return w>other.w;
    }
};
priority_queue<Node,vector<Node>,greater<Node> > pq;
int cnt,head[maxn],to[maxn],val[maxn],nxt[maxn];
bool vis[maxn];
ll dis[maxn];
ll ans,tot;
void addedge(int u,int v,int w){
    cnt++;
    val[cnt]=w;
    to[cnt]=v;
    nxt[cnt]=head[u];
    head[u]=cnt;
}
void Prim(){
    memset(vst,0,sizeof(vst));
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0; pq.push({1,0});
    while(!pq.empty()){
        int u=pq.top().v, d=pq.top().w; pq.pop();
        if(vis[u]) continue;
        // printf("processing %d,length %d\n",u,d);
        vis[u]=true; tot++; ans+=d;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i],w=val[i];
            if(dis[v]>w){
                dis[v]=w;
                pq.push({v,w});
                // printf("pushing {%d,%d} \n",v,w);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w); addedge(v,u,w);
    }
    // for(int i=1;i<=k;i++){
    //     int c;
    //     cin>>c;
    //     for(int j=1;j<=n;j++){
    //         int temp; cin>>temp;
    //         addedge(n+i,j,temp+c); addedge(j,n+i,temp+c);
    //     }
    // }
    Prim();
    cout<<ans<<endl;
    return 0;
}