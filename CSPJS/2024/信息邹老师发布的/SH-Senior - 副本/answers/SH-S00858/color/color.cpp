#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+9,M=1e6+9;
ll T,n,ans,a[N],val[N*4],p[M],pre[N];
inline void pushup(ll now){
	val[now]=max(val[now*2],val[now*2+1]);
}
void change(ll now,ll l,ll r,ll a,ll ret){
	if(l==r){
		val[now]=ret;
		return;
	}
	ll mid=(l+r)>>1;
	if(a<=mid) change(now*2,l,mid,a,ret);
	else change(now*2+1,mid+1,r,a,ret);
	pushup(now);
}
ll query(ll now,ll l,ll r,ll a,ll b){
	if(l>=a&&r<=b){
		return val[now];
	}
	ll mid=(l+r)>>1;
	ll rt=0ll;
	if(a<=mid) rt=max(rt,query(now*2,l,mid,a,b));
	if(b>=mid+1) rt=max(rt,query(now*2+1,mid+1,r,a,b));
	return rt;
}
void build(ll now,ll l,ll r){
	if(l==r){
		val[now]=0;
		return;
	}
	ll mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	pushup(now);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		ans=0;
		memset(pre,0,sizeof(pre));
		memset(p,0,sizeof(p));
		for(ll i=1;i<=n;){
			scanf("%lld",&a[i]);
			if(a[i]==a[i-1]){
				ans+=a[i];
				n--;
				continue;
			}
			pre[i]=p[a[i]];
			p[a[i]]=i;
			i++;
		}
		build(1,1,n);
		for(ll i=2;i<=n;i++){
			if(pre[i]!=0){
				if(pre[i]==1){
					change(1,1,n,i,a[i]);
				}
				else{
					change(1,1,n,i,query(1,1,n,1,pre[i]+1)+a[i]);
				}
			}
		}
		printf("%lld\n",query(1,1,n,1,n)+ans);
	}
	return 0;
}
