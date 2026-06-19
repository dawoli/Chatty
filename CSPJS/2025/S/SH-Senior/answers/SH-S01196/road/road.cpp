#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
char buf[1048577],*p1,*p2;
#define gc() p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++
void rd(int &x){
    x=0; char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
}
const int N=10100,M=1e6+9;
int n,m,k,SJQ[11];
PII a[11][N];
int ps[11];
struct Edge{
    int u,v,w; bool f;
    bool operator<(const Edge &W)const{
        return w<W.w;
    }
}e[M];
int p[N],sz[N];
int ids[11],cnt;
int find(int x){
    return p[x]^x?p[x]=find(p[x]):x;
}
void merge(int x,int y){
    // printf("merge %d %d\n",x,y);
    x=find(x),y=find(y);
    if(sz[x]<sz[y]) swap(x,y);
    p[y]=x,sz[x]+=sz[y];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    rd(n),rd(m),rd(k);
    for(int i=1;i<=m;i++) rd(e[i].u),rd(e[i].v),rd(e[i].w);
    for(int i=1;i<=k;i++){
        rd(SJQ[i]);
        for(int j=1;j<=n;j++) rd(a[i][j].fi),a[i][j].se=j;
        sort(a[i]+1,a[i]+1+n);
        // printf("a %d: ",i); for(int j=1;j<=n;j++) printf("(%d,%d)",a[i][j].fi,a[i][j].se); puts("");
    }
    for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        merge(e[i].u,e[i].v);
        e[i].f=1;
    }
    {
        int mm=m; m=0;
        for(int i=1;i<=mm;i++) if(e[i].f) e[++m]=e[i];
    }
    // printf("MST: "); for(int i=1;i<=m;i++) printf("(%d,%d,%d)",e[i].u,e[i].v,e[i].w); puts("");
    LL res=1e18;
    for(int S=0;S<1<<k;S++){
        LL cost=0;
        cnt=0;
        for(int i=0;i<k;i++) if(S>>i&1) ids[++cnt]=i+1,cost+=SJQ[i+1];
        for(int i=0;i<=10;i++) ps[i]=1;
        for(int i=1;i<=n+k;i++) p[i]=i,sz[i]=1;
        int T=n+cnt-1;
        while(T--){
            while(ps[0]<=m&&find(e[ps[0]].u)==find(e[ps[0]].v)) ps[0]++;
            int mnc=2e9,mn=0;
            if(ps[0]<=m) mnc=e[ps[0]].w;
            for(int i=1,u,t;i<=cnt;i++){
                u=ids[i],t=find(u+n);
                while(ps[i]<=n&&t==find(a[u][ps[i]].se)) ps[i]++;
                if(ps[i]<=n&&mnc>a[u][ps[i]].fi) mnc=a[u][ps[i]].fi,mn=i;
            }
            cost+=mnc;
            if(!mn) merge(e[ps[0]].u,e[ps[0]].v);
            else{
                int u=ids[mn];
                merge(u+n,a[u][ps[mn]].se);
            }
        }
        res=min(res,cost);
        // printf("cost %d %lld\n",S,cost);
    }
    printf("%lld\n",res);
    return 0;
}
