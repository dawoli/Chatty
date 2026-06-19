#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10055;
const int maxm=2000005;
int n,m,k;
int fa[maxn],siz[maxn];
struct E{
    int to,val;
};
struct Edge{
    int u,v,w;
}edge[maxm];
int etot=0;
bool aflag=true;
vector<E>adj[maxn];
int c[15],a[15][maxn];
void fa_init(){
    for(int i=1;i<=maxn-5;i++)fa[i]=i;
    for(int i=1;i<=maxn-5;i++)siz[i]=1;
}
int fa_query(int u){
    if(fa[u]==u)return u;
    else return fa[u]=fa_query(fa[u]);
}
void fa_update(int u,int v){
    u=fa_query(u),v=fa_query(v);
    if(siz[u]>siz[v])swap(u,v);
    siz[v]+=siz[u];fa[u]=v;
}
const int maxk=15;
int suo[maxk],minn[maxk],in[maxk],cache[maxk];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    fa_init();
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        edge[++etot]={u,v,w};
    }
    if(!k){
        int ans=0;
        for(int i=1;i<=m;i++){
            int u,v,w;cin>>u>>v>>w;
            edge[++etot]={u,v,w};
        }
        sort(edge+1,edge+1+etot,[](Edge a,Edge b){
            return a.w<b.w;
        });
        int cnt=1;
        for(int i=1;i<=etot;i++){
            int u=edge[i].u,v=edge[i].v;
            if(cnt>n)break;
            if(fa_query(u)!=fa_query(v)){
                cnt++;
                ans+=edge[i].w;
                fa_update(u,v);
            }
        }cout<<ans<<'\n';
        return 0;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];aflag&=(c[i]==0);
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    if(aflag){
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==0){suo[i]=j;break;}
        for(int i=1;i<=k;i++)
            for(int j=1;j<=n;j++)
                edge[++etot]={suo[i],j,a[i][j]};
        int ans=0;
        sort(edge+1,edge+1+etot,[](Edge a,Edge b){
            return a.w<b.w;
        });
        int cnt=1;
        for(int i=1;i<=etot;i++){
            int u=edge[i].u,v=edge[i].v;
            if(cnt>n)break;
            if(fa_query(u)!=fa_query(v)){
                cnt++;
                ans+=edge[i].w;
                fa_update(u,v);
            }
        }cout<<ans<<'\n';
        return 0;
    }else{
        // for(int i=1;i<=k;i++)minn[i]=0x7fffffffffffffff;
        // for(int i=1;i<=k;i++)
        //     for(int j=1;j<=n;j++)
        //         if(a[i][j]<minn[i]){minn[i]=a[i][j];suo[i]=j;}
        // int ans=0;
        // for(int i=1;i<=k;i++){
        //     ans+=c[i]+a[i][suo[i]];
        //     cache[i]=a[i][suo[i]];
        //     fa_update(n+i,suo[i]);
        // }
        // for(int i=1;i<=k;i++)
            // for(int j=1;j<=n;j++)
                // edge[++etot]={n+i,j,a[i][j]+c[i]};
        // sort(edge+1,edge+1+etot,[](Edge a,Edge b){
        //     return a.w<b.w;
        // });
        // int cnt=1;
        // for(int i=1;i<=etot;i++){
        //     int u=edge[i].u,v=edge[i].v;
        //     if(cnt>n)break;
        //     if(fa_query(u)!=fa_query(v)){
        //         // printf("joining %lld and %lld\n",u,v);
        //         cnt++;
        //         ans+=edge[i].w;
        //         if(u>n)in[u-n]++;
        //         if(v>n)in[v-n]++;
        //         fa_update(u,v);
        //     }
        // }
        // // for(int i=1;i<=k;i++)printf("in[%lld]=%lld\n",i,in[i]);
        // for(int i=1;i<=k;i++)
        //     if(!in[i])ans-=c[i]+cache[i];
        // cout<<ans<<'\n';
        // return 0;
        sort(edge+1,edge+1+etot,[](Edge a,Edge b){
            return a.w<b.w;
        });
        int cnt=1,ans=0;
        for(int i=1;i<=etot;i++){
            int u=edge[i].u,v=edge[i].v;
            if(cnt>n)break;
            if(fa_query(u)!=fa_query(v)){
                cnt++;
                ans+=edge[i].w;
                fa_update(u,v);
            }
        }cout<<ans<<'\n';
        return 0;
    }
    return 0;
}