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
const ll N=2e5+9;
ll T,n,m,L,V,p[N],sv[N],tot;
struct Car{
    ll d,v,a;
}c[N];
struct Seg{
    ll l,r;
}seg[N];
ll Calc(ll d,ll v,ll a){
    return v*v+2*a*d;
}
ll bit[N];
void Upd(ll x,ll k){
    while(x<=m)bit[x]+=k,x+=(x&(-x));
}
ll Query(ll x){
    ll res=0;
    while(x)res+=bit[x],x-=(x&(-x));
    return res;
}
void solve(){
    n=read(),m=read(),L=read(),V=read();
    rep(i,1,n)c[i].d=read(),c[i].v=read(),c[i].a=read();
    rep(i,1,m)p[i]=read();
    rep(i,0,m+1)sv[i]=0,bit[i]=0;
    tot=0;
    sort(p+1,p+m+1);
    ll cnt=0;
    rep(i,1,n){
        if(c[i].a>=0){
            if(p[m]<c[i].d)continue;
            ll ev=Calc(p[m]-c[i].d,c[i].v,c[i].a);
            if(ev>V*V){
                cnt++;
                ll l=1,r=m,st=0;
                while(l<=r){
                    ll mid=(l+r)>>1;
                    if(p[mid]>=c[i].d&&Calc(p[mid]-c[i].d,c[i].v,c[i].a)>=V*V)st=mid,r=mid-1;
                    else l=mid+1;
                }
                seg[++tot]={st,m};
            }
        }
    }
    rep(i,1,n){
        if(c[i].a>=0)continue;
        ll l=1,r=m,st=0;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(p[mid]>=c[i].d)st=mid,r=mid-1;
            else l=mid+1;
        }
        if(!st)continue;
        l=st,r=m;
        ll ed=0;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(Calc(p[mid]-c[i].d,c[i].v,c[i].a)>V*V)ed=mid,l=mid+1;
            else r=mid-1;
        }
        if(st>ed)continue;
        seg[++tot]={st,ed},cnt++;
    }
    sort(seg+1,seg+tot+1,[&](Seg a,Seg b){
        return a.r<b.r;
    });
    rep(i,1,tot){
        if(Query(seg[i].r)-Query(seg[i].l-1))continue;
        Upd(seg[i].r,1),sv[seg[i].r]=1;
    }
    write(cnt),putchar(' '),write(m-accumulate(sv+1,sv+m+1,0ll)),putchar('\n');
}
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    T=read();
    while(T--)solve();
    cerr<<"\n"<<clock()*1000./CLOCKS_PER_SEC<<"ms\n";
    return 0;
}