#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1.1e6+10,K=20,V=1e5+10; int c[K],a[K][N],fa[N+K],use[K];
struct Edge { int u,v,w; }e1[M],e2[V],e[M];
bool cmp(Edge a,Edge b) { return a.w<b.w; }
int getfa(int x) { return (fa[x]==x?x:fa[x]=getfa(fa[x])); }
int read() {
    int ans=0; char ch=getchar_unlocked();
    while(ch<'0'||ch>'9') ch=getchar_unlocked();
    while(ch>='0'&&ch<='9') ans=ans*10+ch-'0',ch=getchar_unlocked();
    return ans;
}
void print(long long x) {
    int sta[25],cnt=0;
    while(x) sta[++cnt]=x%10,x/=10;
    do cout<<sta[cnt],cnt--; while(cnt);
}
int main() {
    //clock_t s=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,m,k; n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) e1[i].u=read(),e1[i].v=read(),e1[i].w=read();
    for(int i=1;i<=k;i++) {
        c[i]=read();
        for(int j=1;j<=n;j++) a[i][j]=read(),e2[(i-1)*n+j]={i+n,j,a[i][j]};
    }
    sort(e1+1,e1+m+1,cmp),sort(e2+1,e2+k*n+1,cmp);
    long long ans=9e18;
    for(int sta=0;sta<(1<<k);sta++) {
        int res=0; long long sum=0;
        for(int i=1;i<=k;i++) use[i]=((sta>>(i-1))&1),res+=use[i],sum+=use[i]*c[i];
        int tot=0,l=1,r=1;
        while(l<=m&&r<=k*n) {
            while(r<=k*n&&!use[(e2[r].u-n-1)/n+1]) r++;
            if(e1[l].w<e2[r].w) e[++tot]=e1[l++];
            else if(r<=k*n) e[++tot]=e2[r++];
        }
        while(l<=m) e[++tot]=e1[l++];
        while(r<=k*n) {
            while(r<=k*n&&!use[(e2[r].u-n-1)/n+1]) r++;
            if(r<=k*n) e[++tot]=e2[r++];
        }
        for(int i=1;i<=n+k;i++) fa[i]=i;
        int cnt=0;
        for(int i=1;i<=tot;i++) {
            int u=getfa(e[i].u),v=getfa(e[i].v);
            if(u==v) continue;
            fa[u]=v,cnt++,sum+=e[i].w;
            if(cnt==n+res-1) break;
        }
        ans=min(ans,sum);
    }
    print(ans);
    //clock_t e=clock();
    //cout<<'\n'<<(double)(e-s)/CLOCKS_PER_SEC;
    return 0;
}
