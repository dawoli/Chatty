#include <bits/stdc++.h>
using namespace std;

bool be_M;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<typename T>
void read(T &a){
    a=0;char c;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
namespace GSK{
typedef long long ll;
const int MAXN=2000010;
int n,m,k;
struct Edge{
    int u,v,w;
};
Edge a[12][MAXN];
int c[12];
int ufa[MAXN];int gf(int x){return ufa[x]==x?x:ufa[x]=gf(ufa[x]);}
int pt[12];
void main(){
    read(n),read(m),read(k);
    for(int i=1;i<=m;++i){
        read(a[0][i].u),read(a[0][i].v),read(a[0][i].w);
    }
    sort(a[0]+1,a[0]+m+1,[&](Edge x,Edge y){return x.w<y.w;});
    bool A=1;
    for(int i=1;i<=k;++i){
        read(c[i]);
        for(int j=1;j<=n;++j)read(a[i][j].w),a[i][j].u=n+i,a[i][j].v=j;
        sort(a[i]+1,a[i]+n+1,[&](Edge x,Edge y){return x.w<y.w;});
        A&=c[i]==0;
    }
    int uL=0,uR=(1<<k)-1;
    if(A)uL=uR;
    ll ans=1e18;
    for(int mask=uL;mask<=uR;++mask){
        // cerr<<"mas "<<mask<<endl;
        ll anss=0;
        int cnt=n;
        for(int i=0;i<k;++i)
            if(mask>>i&1){
                anss+=c[i+1];
                cnt++;
            }
        for(int i=1;i<=n+k;++i)ufa[i]=i;
        for(int i=0;i<=k;++i)pt[i]=1;
        for(int i=1;cnt>1;++i){
            int u,v,w;
            int p=0;
            for(int j=1;j<=k;++j)if(mask>>(j-1)&1)
                if(pt[j]<=n&&(p==-1||a[p][pt[p]].w>a[j][pt[j]].w))
                    p=j;
            // printf("W %d %d %d %d fl %d %d %d - %d %d\n",w,p,pt[p],i,cnt,n,mask,u,v);
            u=gf(a[p][pt[p]].u);
            v=gf(a[p][pt[p]].v);
            w=a[p][pt[p]].w;
            pt[p]++;
            // printf("W %d %d %d %d fl %d %d %d - %d %d\n",w,p,pt[p],i,cnt,n,mask,u,v);
            if(u==v)continue;
            cnt--;
            anss+=w;
            ufa[u]=v;
        }
        // printf("%lld\n",anss);
        ans=min(ans,anss);
    }
    printf("%lld\n",ans);
}
}
bool ed_M;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)GSK::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&be_M)/1024.0/1024.0<<" MB"<<endl;
    return 0;
}