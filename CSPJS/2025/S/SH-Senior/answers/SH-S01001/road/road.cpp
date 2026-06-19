#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[20],cnt,fa[10020],sz[10020];
bool b[10020];
long long cur,ans;
struct E {
    int u,v,w;
    bool operator<(const E &x) const {
        return w<x.w;
    }
} e0[1000010],e[110010];
int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y) {
    if (!b[x]) return false;
    x=find(x);
    y=find(y);
    if (x==y) return false;
    if (sz[x]<sz[y]) swap(x,y);
    fa[y]=x;
    sz[x]+=sz[y];
    return true;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;++i) cin>>e0[i].u>>e0[i].v>>e0[i].w;
    sort(e0+1,e0+m+1);
    for (int i=1;i<=n;++i) fa[i]=i,sz[i]=1,b[i]=1;
    for (int i=1;i<=m;++i) if (merge(e0[i].u,e0[i].v)) e[++cnt]=e0[i];
    for (int i=1;i<=k;++i) {
        cin>>c[i];
        for (int j=1;j<=n;++j) {
            cin>>e[++cnt].w;
            e[cnt].u=n+i;
            e[cnt].v=j;
        }
    }
    sort(e+1,e+cnt+1);
    ans=1e18;
    for (int i=0;i<(1<<k);++i) {
        cur=0;
        for (int j=1;j<=n+k;++j) fa[j]=j,sz[j]=1;
        for (int j=1;j<=k;++j) if (i>>j-1&1) {
            b[j+n]=1;
            cur+=c[j];
        }
        for (int j=1;j<=cnt;++j) if (merge(e[j].u,e[j].v)) cur+=e[j].w;
        for (int j=1;j<=k;++j) b[j+n]=0;
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}