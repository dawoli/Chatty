#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,l,V;
ll d[100005],a[100005],v[100005];
ll p[100005];
bool vis[100005];
ll pos[1000006];
ll check() {
	ll cnt=0;
	for(ll i=1;i<=n;i++) {
		for(ll j=1;j<=m;j++) {
			if(!vis[j]&&p[j]>=d[i]&&v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}
ll ans,sum,maxsum;
void dfs(ll u) {
	if(u==m+1) {
		if(check()==ans) maxsum=max(maxsum,sum);
		return;
	}
	vis[u]=0;
	dfs(u+1);
	vis[u]=1;
	sum++;
	dfs(u+1);
	sum--;
	vis[u]=0;
	return;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll t;
	cin>>t;
	while(t--) {
		bool point34=1,point56=1,point78=1;
		cin>>n>>m>>l>>V;
		ll maxp=0;
		for(ll i=1;i<=n;i++) {
			scanf("%lld%lld%lld",d+i,v+i,a+i);
		}
		for(ll i=1;i<=m;i++) {
			scanf("%lld",&p[i]);
			maxp=max(maxp,p[i]);
		}
		for(ll i=1;i<=n;i++) {
			if(a[i]!=0) point34=0;
			if(a[i]<=0) point56=0;
			if(a[i]>=0) point78=0;
		}
		if(n<=20) {
			printf("%lld ",(ans=check()));
			maxsum=0;
			dfs(1);
			printf("%lld\n",maxsum);
		}
		else if(point34) {
			ll cnt=0;
			for(ll i=1;i<=n;i++) if(v[i]>V&&d[i]<=maxp) ++cnt;
			printf("%lld %lld\n",cnt,m-!!cnt);
		}
		else if(point56) {
			ll cnt=0;
			for(ll i=1;i<=n;i++) if(v[i]*v[i]+2*a[i]*(maxp-d[i])>V*V&&d[i]<=maxp) ++cnt;
			printf("%lld %lld\n",cnt,m-!!cnt);
		}
		else {
			printf("0 %lld\n",m);
		}
	}
	return 0;
}
