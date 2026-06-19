#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pii pair<ll,ll>
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
using namespace std;
bool Mbe;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch))x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
void write(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const ll N=(1<<17)+9;
ll T,n,m,K,a[N],qc[N],leaf[N],X[4],ans[N];
ll nowK[N],mx,deep[N<<1];
ll stasum[18];
char num[18][N];
ll now[18];
ll win[N<<1][18],hwin[N<<1];
bool rnum[N<<1];
void Build(ll x,ll l,ll r,ll dep){
    mx=max(mx,x),deep[x]=dep;
    if(l==r)return leaf[l]=x,hwin[x]=l,void();
    now[dep]++;
    rnum[x]=num[dep][now[dep]]-'0';
    ll mid=(l+r)>>1;
    Build(x<<1,l,mid,dep-1);
    Build(x<<1|1,mid+1,r,dep-1);
    hwin[x]=hwin[x<<1]+hwin[x<<1|1];
}
void solve(){
    memset(now,0,sizeof(now));
    Build(1,1,(1<<K),K);
    rep(i,0,mx)memset(win[i],0,sizeof(win[i]));
    ll rt=leaf[1];
    rep(i,1,n){
        if(nowK[i]!=nowK[i-1])rt=rt>>1;
        ll u=leaf[i];
        win[u][min(a[i],K)]=i,hwin[u]=0;
        if(u!=rt){
            do{
                u>>=1;
                ll ls=u<<1,rs=u<<1|1,tar=deep[u];
                if(rnum[u]==1)swap(ls,rs);
                hwin[u]=0;
                ll fl=0;
                rep(j,0,K){
                    // if(!win[ls][j])continue;
                    if(j<tar)fl|=win[ls][j],win[u][j]=0;
                    else win[u][j]=win[ls][j];
                }
                if(fl||hwin[ls]){
                    rep(j,0,K){
                        // if(!win[rs][j])continue;
                        win[u][j]+=win[rs][j];
                    }
                    hwin[u]=hwin[ls]+hwin[rs];
                }
                else hwin[u]=hwin[ls];
            }while(u!=rt);
        }
        ans[i]=accumulate(win[rt],win[rt]+K+1,0ll)+hwin[rt];
    }
    ll res=0;
    rep(i,1,m)res^=(i*ans[qc[i]]);
    write(res),putchar('\n');
}
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    n=read(),m=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,m)qc[i]=read();
    rep(i,1,n){
        while((1ll<<nowK[i])<i)nowK[i]++;
    }
    while((1ll<<K)<n)K++;
    rep(i,1,K)scanf("%s",num[i]+1);
    T=read();
    while(T--){
        rep(i,0,3)X[i]=read();
        rep(i,1,n)a[i]^=X[i&3];
        solve();
        rep(i,1,n)a[i]^=X[i&3];
    }
    cerr<<"\n"<<clock()*1000./CLOCKS_PER_SEC<<"ms\n";
    return 0;
}