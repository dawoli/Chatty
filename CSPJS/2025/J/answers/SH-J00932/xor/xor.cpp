#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s{
	ll l,r;
}q[500050];
/*
struct tree{
	int l,r,x,maxn;
}t[2000050];
void build(ll p,ll l,ll r){
	if(l>r)return;
	t[p].l=l;
	t[p].r=r;
	if(l==r)return;
	ll mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void pushdown(ll p){
	t[p<<1].x=max(t[p<<1].x,t[p].maxn);
	t[p<<1|1].x=max(t[p<<1|1].x,t[p].maxn);
	t[p<<1].maxn=t[p].maxn;
	t[p<<1|1].maxn=t[p].maxn;
	t[p].maxn=0;
}
ll ask(ll p,ll x){
	if(t[p].l==t[p].r)return t[p].x;
	pushdown(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(t[p].l<=x&&x<=mid)return ask(p<<1,x);
	else return ask(p<<1|1,x);
}
void change(ll p,ll l,ll r,ll x){
	if(t[p].r<l)return;
	if(t[p].l>r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].x=max(t[p].x,(int)x);
		t[p].maxn=max(t[p].maxn,(int)x);
		return;
	}
	pushdown(p);
	ll mid=(l+r)>>1;
	if(l<=mid)change(p<<1,l,r,x);
	if(r>mid)change(p<<1|1,l,r,x);
	t[p].x=max(t[p<<1].x,t[p<<1|1].x);
}
*/
ll n,m,a[500050],b[500050],idx=1,dp[500050],sum,maxn;
map<ll,ll> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	v[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
		b[i]=b[i-1] xor a[i];
		if(v.count(b[i] xor m)){
			//v[b[i] xor m]+1,i
			q[idx++]={v[b[i] xor m]+1,i};
		}
		v[b[i]]=i;
	}
	/*
	for(int i=1;i<idx;i++){
		cout<<q[i].l<<" "<<q[i].r<<"\n";
	}
	*/
	if(maxn<=1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)sum++;
		}
		printf("%lld",sum);
		return 0;
	}
	//build(1,1,n);
	for(int i=1;i<idx;i++){
		
		for(int j=q[i].r;j<=n+10;j++){
			dp[j]=max(dp[j],dp[q[i].l-1]+1);
		}
		
		//change(1,q[i].r,n,ask(1,q[i].l-1)+1);
	}
	printf("%lld",dp[n+10]);
	//printf("%lld",ask(1,n));
	return 0;
}
