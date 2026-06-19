#include <stdio.h>
#include <algorithm>
#define min(a,b) (a)<(b)?(a):(b)
const int MAXM=1.1e6+10;
const int MAXN=2e4+10;
const int MAXK=15;
struct Edge{
    int u,v;
    long long w;
}es[MAXM];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int pre[MAXN];
void init(int n){
    for (int i=0;i<=n;++i){
        pre[i]=i;
    }
}
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}
bool iscity[MAXN];
long long kruskal(int n,int m){
    init(n);
    long long ans=0;
    for (int i=1;i<=m;++i){
        if (!(iscity[es[i].u]&&iscity[es[i].v])) continue;
        if (find(es[i].u)==find(es[i].v)) continue;
        ans+=es[i].w;
        pre[find(es[i].u)]=find(es[i].v);
    }
    return ans;
}
long long c[MAXK];

void solve(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;++i){
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        es[i]={u,v,w};
        
    }
    for (int i=1;i<=n;++i){
        iscity[i]=1;
    }
    for (int i=1;i<=k;++i){
        scanf("%lld",&c[i]);
        for (int j=1;j<=n;++j){
            long long t;
            scanf("%lld",&t);
            es[++m]={i+n,j,t};
        }
    }
    std::sort(es+1,es+m+1,cmp);
    
    long long fans=1e18+10;
    for (int i=0;i<(1<<k);++i){
        long long ans=0;
        for (int j=0;j<k;++j){
            if ((i>>j)&1){
                ans+=c[j+1];
                iscity[j+n+1]=1;
            }
        }
        ans+=kruskal(n+k,m);
        for (int j=0;j<k;++j){
            iscity[j+n+1]=0;
        }
        fans=min(ans,fans);
    }
    printf("%lld\n",fans);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}