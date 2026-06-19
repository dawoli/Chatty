#include<bits/stdc++.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define ll long long
int read(){
    int x=0;
    bool neg=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        neg|=(ch=='-'),
        ch=gc();
    while(ch>='0'&&ch<='9')
        x=x*10+(ch^48),
        ch=gc();
    return neg?-x:x; //             -2147483648 bug
}
const int LMT=10004;
int n,m,k;
struct edge{
    int u,v,w;
    friend bool operator <(const edge &a,const edge &b){
        return a.w<b.w;
    }
}tr[LMT],e[LMT*100],ex[11][LMT],cur_e[LMT*11];
struct graph_connection{
    int fa[LMT+10],sz[LMT+10];
    void init(){
        for(int i=1;i<=n+k;i++)
            fa[i]=i,
            sz[i]=1;
    }
    int root(int u){
        return fa[u]==u?u:(fa[u]=root(fa[u]));
    }
    bool query_connected(int u,int v){
        u=root(u);v=root(v);
        return u==v;
    }
    void connect(int u,int v){
        u=root(u);v=root(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        sz[u]+=sz[v];
        fa[v]=u;
    }
    bool all_connected(){
        return sz[root(1)]==n+k;// >=
    }
}G;
int exv[11];
ll ans=1e15,cur;
void use(edge E){
    if(G.query_connected(E.u,E.v))return;
    G.connect(E.u,E.v);
    cur+=E.w;
}
int ed;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++){
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    G.init();
    sort(e+1,e+m+1);
    for(int T=1,i=1;T<n;T++){
        while(G.query_connected(e[i].u,e[i].v))i++;
        G.connect(e[i].u,e[i].v);
        tr[T]=e[i];
    }
    for(int i=1;i<=k;i++){
        exv[i]=read();
        for(int j=1;j<=n;j++){
            ex[i][j].u=n+i;
            ex[i][j].v=j;
            ex[i][j].w=read();
        }
        sort(ex[i]+1,ex[i]+n+1);
    }
    for(int sta=0;sta<(1<<k);sta++){
        cur=0;
        for(int i=1;i<n;i++)
            cur_e[i]=tr[i];
        ed=n;
        G.init();
        for(int i=1;i<=k;i++)
            if(sta&(1<<(i-1))){
                cur+=exv[i];
                for(int j=1;j<=n;j++)
                    cur_e[ed++]=ex[i][j];
                inplace_merge(cur_e+1,cur_e+(ed-n),cur_e+ed);
            }else G.connect(i+n,1);
        for(int i=1;!G.all_connected();i++)
            use(cur_e[i]);
        ans=min(ans,cur);
    }
    printf("%lld\n",ans);
    return 0;
}