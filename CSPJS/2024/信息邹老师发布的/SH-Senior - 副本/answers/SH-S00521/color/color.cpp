#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
const ll N=200009;
const ll M=1000009;
ll T,n;
ll a[N];
ll g[N];
ll p[N],pos[M];
struct Segment{
	ll l,r,mx,tag;
} tr[N*4];
void build(ll u,ll l,ll r){
	tr[u]={l,r,0,0};
	if(l==r) return;
	ll mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
}
inline void pushup(ll u){
	tr[u].mx=max(tr[u*2].mx,tr[u*2+1].mx);
}
inline void pushdown(ll u){
	tr[u*2].tag+=tr[u].tag;
	tr[u*2].mx+=tr[u].tag;
	tr[u*2+1].tag+=tr[u].tag;
	tr[u*2+1].mx+=tr[u].tag;
	tr[u].tag=0;
}
inline void add(ll u,ll l,ll r,ll x){
	if(l<=tr[u].l&&r<=tr[u].r){
		tr[u].tag+=x;
		tr[u].mx+=x;
		return;
	}
	pushdown(u);
	ll mid=(tr[u].l+tr[u].r)/2;
	if(l<=mid){
		add(u*2,l,r,x);
	}
	if(mid<r){
		add(u*2+1,l,r,x);
	}
	pushup(u);
}
inline ll query(ll u,ll x){
	if(tr[u].l==tr[u].r){
		return tr[u].mx;
	}
	pushdown(u);
	ll mid=(tr[u].l+tr[u].r)/2;
	ll res=0;
	if(x<=mid){
		return query(u*2,x);
	}
	else{
		return query(u*2+1,x);
	}
}
inline void upd(ll u,ll x,ll z){
	if(tr[u].l==tr[u].r){
		tr[u].mx=z;
		return;
	}
	pushdown(u);
	ll mid=(tr[u].l+tr[u].r)/2;
	if(x<=mid){
		upd(u*2,x,z);
	}
	else{
		upd(u*2+1,x,z);
	}
	pushup(u);
}
const ll B=1;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(ll i=1;i<=n;i++){
			a[i]=read();
			p[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		build(1,1,n+1);
		for(ll i=1;i<=n;i++){
			upd(1,i-1+B,g[i-1]);
			g[i]=tr[1].mx;
			if(p[i]==0) continue;
			if(p[i]==i-1){
				add(1,0+B,i-2+B,a[i]);
				g[i]=tr[1].mx;
				continue;
			}
			upd(1,i-1+B,max(g[i-1],query(1,p[i]+B)+a[i]));
			g[i]=tr[1].mx;
		}
		printf("%lld\n",g[n]);
		for(ll i=1;i<=n;i++){
			pos[a[i]]=0;
		}
	}
	return 0;
}

