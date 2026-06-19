#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define M 1000000
#define ll long long
int T,n,p,q,lst[M+9],pre[N];ll a[N],val,ans;
struct seg{
	ll x[N<<2],t[N<<2];
	void build(int pl,int pr,int p){
		x[p]=t[p]=0;
		if(pl==pr)return;
		int mid=(pl+pr)>>1;
		build(pl,mid,p<<1);build(mid+1,pr,p<<1|1);
	}
	inline void tg(int p,ll d){x[p]+=d,t[p]+=d;}
	inline void pd(int p){if(t[p])tg(p<<1,t[p]),tg(p<<1|1,t[p]),t[p]=0;}
	void upd(int l,int r,int pl,int pr,int p,ll d){
		if(l<=pl&&pr<=r){tg(p,d);return;}
		pd(p);int mid=(pl+pr)>>1;
		if(l<=mid)upd(l,r,pl,mid,p<<1,d);
		if(r>mid)upd(l,r,mid+1,pr,p<<1|1,d);
		x[p]=max(x[p<<1],x[p<<1|1]);
	}
	ll qr(int l,int r,int pl,int pr,int p){
		if(l<=pl&&pr<=r)return x[p];
		pd(p);int mid=(pl+pr)>>1;ll res=-0x3f3f3f3f3f3f3f3fll;
		if(l<=mid)res=max(res,qr(l,r,pl,mid,p<<1));
		if(r>mid)res=max(res,qr(l,r,mid+1,pr,p<<1|1));
		return res;
	}
}tr;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=1;i<=M;++i)lst[i]=0;
		for(int i=1;i<=n;++i)pre[i]=lst[a[i]],lst[a[i]]=i;
		tr.build(0,n,1);
		for(int i=2;i<=n;++i){
			val=tr.qr(0,i-2,0,n,1);
			if(pre[i])val=max(val,tr.qr(pre[i],pre[i],0,n,1)+a[i]);
			tr.upd(i-1,i-1,0,n,1,val);
			if(a[i]==a[i-1])tr.upd(0,i-2,0,n,1,a[i]);
		}
		printf("%lld\n",tr.qr(0,n-1,0,n,1));
	}
	return 0;
}
