#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5+5;
const int M = 1e6;
int a[N];
int n;

ll mx[N*4],add[N*4];
void build(int o,int l,int r){
    add[o]=0;
    if(l==r){
        if(!l)mx[o]=0;
        else mx[o]=-1e18;
        return;
    }

    int lch=o<<1,rch=o<<1|1;
    int mid=(l+r)>>1;
    build(lch,l,mid),build(rch,mid+1,r);
    mx[o]=max(mx[lch],mx[rch]);
}
void pushdown(int o){
    int lch=o<<1,rch=o<<1|1;
    mx[lch] += add[o], mx[rch] += add[o];
    add[lch]+=add[o], add[rch]+=add[o];
    add[o]=0;
}
void modify(int o,int l,int r,int ql,int qr,ll k){
    if(ql<=l&&r<=qr){
        mx[o] += k;
        add[o] += k;
        return;
    }
    pushdown(o);
    int lch=o<<1,rch=o<<1|1;
    int mid=(l+r)>>1;
    if(ql<=mid)modify(lch,l,mid,ql,qr,k);
    if(qr>mid)modify(rch,mid+1,r,ql,qr,k);
    mx[o]=max(mx[lch],mx[rch]);
}
void upd(int o,int l,int r,int i,ll k){
    if(l==r){
        mx[o] = max(mx[o], k);
        return;
    }
    pushdown(o);
    int lch=o<<1,rch=o<<1|1;
    int mid=(l+r)>>1;
    if(i<=mid)upd(lch,l,mid,i,k);
    else upd(rch,mid+1,r,i,k);
    mx[o]=max(mx[lch],mx[rch]);
}
ll query(int o,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return mx[o];
    pushdown(o);
    int lch=o<<1,rch=o<<1|1;
    int mid=(l+r)>>1;
    if(qr<=mid)return query(lch,l,mid,ql,qr);
    if(ql>mid)return query(rch,mid+1,r,ql,qr);
    return max(query(lch,l,mid,ql,qr), query(rch,mid+1,r,ql,qr));
}

void debug(int x){
    for(int i=0;i<=x;i++)cout<<query(1,0,x,i,i)<<' ';
    cout<<'\n';
}

int p[M+5];

void solve(){
    for(int i=0;i<=M;i++)p[i]=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        if(!p[a[i]])p[a[i]]=++tot;
    }

    build(1,0,tot);
//    debug(tot);
    for(int i=1;i<=n;i++){
        int now = p[a[i]];
        ll tmp = max(query(1,0,tot,now,now)+a[i],query(1,0,tot,0,now-1));
        if(now!=tot)tmp=max(tmp,query(1,0,tot,now+1,tot));

        if(a[i]==a[i-1])modify(1,0,tot,0,tot,a[i]);

        upd(1,0,tot,p[a[i-1]],tmp);

//        debug(tot);
    }

    cout << mx[1] << '\n';
}



int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }
    return 0;
}
