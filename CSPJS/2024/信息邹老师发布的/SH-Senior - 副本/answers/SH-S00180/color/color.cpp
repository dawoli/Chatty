#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
const ll N=2e5+9,INF=1e16;
ll T,n,a[N],tmp[N],K;
ll tr[N<<2],tag[N<<2];
void Pushup(ll x){
    tr[x]=max(tr[x<<1],tr[x<<1|1]);
}
void Build(ll x,ll l,ll r){
    tr[x]=-INF,tag[x]=0;
    if(l==r){
        if(l==0)tr[x]=0;
        return ;
    }
    ll mid=(l+r)>>1;
    Build(x<<1,l,mid),Build(x<<1|1,mid+1,r);
    Pushup(x);
}
void Pushtag(ll x,ll k){
    tr[x]+=k,tag[x]+=k;
}
void Pushdown(ll x){
    if(!tag[x])return ;
    Pushtag(x<<1,tag[x]);
    Pushtag(x<<1|1,tag[x]);
    tag[x]=0;
}
void Upd(ll x,ll l,ll r,ll ql,ll qr,ll k){
    if(ql<=l&&r<=qr)return Pushtag(x,k),void();
    ll mid=(l+r)>>1;
    Pushdown(x);
    if(ql<=mid)Upd(x<<1,l,mid,ql,qr,k);
    if(qr>mid)Upd(x<<1|1,mid+1,r,ql,qr,k);
    Pushup(x);
}
void Cov(ll x,ll l,ll r,ll u,ll v){
    if(l==r)return tr[x]=v,void();
    ll mid=(l+r)>>1;
    Pushdown(x);
    if(u<=mid)Cov(x<<1,l,mid,u,v);
    else Cov(x<<1|1,mid+1,r,u,v);
    Pushup(x);
}
ll Query(ll x,ll l,ll r,ll ql,ll qr){
    if(ql<=l&&r<=qr)return tr[x];
    ll mid=(l+r)>>1;
    Pushdown(x);
    if(qr<=mid)return Query(x<<1,l,mid,ql,qr);
    if(ql>mid)return Query(x<<1|1,mid+1,r,ql,qr);
    return max(Query(x<<1,l,mid,ql,qr),Query(x<<1|1,mid+1,r,ql,qr));
}

void solve(){
    n=read();
    rep(i,1,n)a[i]=read(),tmp[i]=a[i];
    sort(tmp+1,tmp+n+1);
    K=unique(tmp+1,tmp+n+1)-tmp-1;
    rep(i,1,n)a[i]=lower_bound(tmp+1,tmp+K+1,a[i])-tmp;
    Build(1,0,K);
    rep(i,1,n){
        ll mx=tr[1],mx2=Query(1,0,K,a[i],a[i]);
        if(a[i]==a[i-1])Upd(1,0,K,0,K,tmp[a[i]]);
        Cov(1,0,K,a[i-1],max(mx,mx2+tmp[a[i]]));
    }
    write(tr[1]),putchar('\n');
}
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    T=read();
    while(T--)solve();
    cerr<<"\n"<<clock()*1000./CLOCKS_PER_SEC<<"ms\n";
    return 0;
}