#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll T,n,m,l,maxv;
struct node{
	ll pos_in,v,a;
}car[N];
bool fast[N];
ll detect[N];
namespace bf{
	ll ans;
	bool off[N];
	void chkans() {
		for (ll i=1;i<=n;++i) {
			if (!fast[i]) continue;
			bool can=false;
			for (ll j=1;j<=m;++j) {
				if (off[j]) continue;
				if (detect[j]<car[i].pos_in) continue;
				ll speed=(ll)car[i].v*car[i].v+2*car[i].a*(detect[j]-car[i].pos_in);
				if (speed>(ll)maxv*maxv) {
					can=true;
					break;
				}
			}
			if (!can) return;
		}
		ll res=0;
		for (ll i=1;i<=m;i++) {
			if (off[i]) ++res;
		}
		ans=max(ans,res);
	}
	void dfs(ll la) {
		if (la==m) {
			chkans();
			return;
		} 
		for (ll j=la+1;j<=m;++j) {
			off[j]=true;
			dfs(j);
			off[j]=false;
			dfs(j);
		}
	}
	void solve() {
		ll res1=0;
		for (ll i=1;i<=n;++i) {
			for (ll j=1;j<=m;++j) {
				if (detect[j]<car[i].pos_in) continue;
				ll speed=car[i].v*car[i].v+2*car[i].a*(detect[j]-car[i].pos_in);
				if (speed>maxv*maxv) {
					fast[i]=true;
					++res1;
					break;
				}
			}
		}
		printf("%lld ",res1);
		for (ll j=1;j<=m;++j) {
			off[j]=false;
		}
		ans=0;
		dfs(0);
		printf("%lld\n",ans);
	}
}
namespace azero{
	void solve() {
		ll res1=0;
		for (ll i=1;i<=n;++i) {
			if (car[i].v<=maxv) continue;
			if (car[i].pos_in>detect[m]) continue;
			++res1;
		}
		printf("%lld ",res1);
		
		if (res1==0) printf("%lld\n",m);
		else printf("%lld\n",m-1);
	}
}
namespace abig{
	void solve() {
		ll res1=0;
		for (ll i=1;i<=n;++i) {
			if (car[i].pos_in>detect[m]) continue;
			ll v=(ll)car[i].v*car[i].v+2*car[i].a*(detect[m]-car[i].pos_in);
			if (v>(ll)maxv*maxv) ++res1;
		}
		printf("%lld ",res1);
		
		if (res1==0) printf("%lld\n",m);
		else printf("%lld\n",m-1);
	}
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld%lld%lld%lld",&n,&m,&l,&maxv);
		for (ll i=1;i<=n;++i) {
			fast[i]=false;
			scanf("%lld%lld%lld",&car[i].pos_in,&car[i].v,&car[i].a);
		}
		for (ll j=1;j<=m;++j) {
			scanf("%lld",&detect[j]);
		}
		sort(detect+1,detect+m+1);
		if (n<=20) {
			bf::solve();
			continue;
		}
		bool allzero=true;
		for (ll i=1;i<=n;++i) {
			if (car[i].a!=0) allzero=false;
		}
		if (allzero) {
			azero::solve();
			continue;
		} 
		bool allbig=true;
		for (ll i=1;i<=n;++i) {
			if (car[i].a<=0) allbig=false;
		}
		if (allbig) {
			abig::solve();
			continue;
		} 
	}
	return 0;
}
/*
当车辆行驶到主干道最北端（即距离最南端为 L 的位置）， 
或速度降为 0（这只可能在 a i < 0 时发生）时，
我们认为该车驶离主干道。

第 j 个测速仪位于主干道上距离最南端 p j 的位置。 

当车辆驶入与驶出主干道时，
如果在对应位置有一个开启的测速仪，
这个测速仪也会对这辆车进行测速。 

***首先，如果所有测速仪都是开启的，那么这 n 辆车中会有多少辆车被判定为超速。

他们希望在关闭一部分测速仪以后它依然被判定为超速。

***在这样的条件下最多可以关闭多少测速仪。
*/
