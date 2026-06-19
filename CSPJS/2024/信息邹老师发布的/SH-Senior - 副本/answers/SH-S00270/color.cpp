#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,V=1e6+5;
int tl,n,a[N];long long w;
long long mx[V<<2],tg[V<<2];

void pushdown(int p){
    if(tg[p]){
        mx[p*2]+=tg[p],mx[p*2+1]+=tg[p];
        tg[p*2]+=tg[p],tg[p*2+1]+=tg[p];tg[p]=0;
    }
}

void pushup(int p){
    mx[p]=max(mx[p*2],mx[p*2+1]);
}

void build(int p,int l,int r){
    mx[p]=-1e18;if(l==r)return;int mid=(l+r)>>1;
    build(p*2,l,mid);build(p*2+1,mid+1,r);
}

void ch(int p,int l,int r,int pt,long long v){
    if(l==r){mx[p]=max(mx[p],v);return;}int mid=(l+r)>>1;pushdown(p);
    if(pt<=mid)ch(p*2,l,mid,pt,v);else ch(p*2+1,mid+1,r,pt,v);pushup(p);
}

void add(int p,int l,int r,int ll,int rr,long long v){
    if(ll<=l&&r<=rr){mx[p]+=v;tg[p]+=v;return;}int mid=(l+r)>>1;pushdown(p);
    if(ll<=mid)add(p*2,l,mid,ll,rr,v);if(rr>mid)add(p*2+1,mid+1,r,ll,rr,v);pushup(p);
}

long long ask(int p,int l,int r,int pt){
    if(l==r)return mx[p];int mid=(l+r)>>1;pushdown(p);
    if(pt<=mid)return ask(p*2,l,mid,pt);else return ask(p*2+1,mid+1,r,pt);
}

void solve(){
    cin>>n;build(1,1,V-5);
    for(int i=1;i<=n;i++)cin>>a[i];
    ch(1,0,V-5,0,0);
    for(int i=2;i<=n;i++){
        w=max(mx[1],ask(1,0,V-5,a[i])+a[i]);
        add(1,0,V-5,0,V-5,a[i]*(a[i]==a[i-1]));
        ch(1,0,V-5,a[i-1],w);
    }cout<<mx[1]<<"\n";
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin>>tl;
    for(int i=1;i<=tl;i++)solve();
    return 0;
}