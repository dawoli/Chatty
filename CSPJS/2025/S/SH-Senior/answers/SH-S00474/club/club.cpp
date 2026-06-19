#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
	ll a,b,c;
} a[100010];
ll t,n,ans;
bool cmp(const node &x,const node &y) {
	return x.a-x.b>y.a-y.b;
}
void dfs(ll stp,ll sum,ll c1,ll c2,ll c3) {
	if(stp>n) {
		ans=max(ans,sum);
		return;
	}
	if((a[stp].a>=a[stp].b||a[stp].a>=a[stp].c) && c1<n/2) dfs(stp+1,sum+a[stp].a,c1+1,c2,c3);
	if((a[stp].b>=a[stp].a||a[stp].b>=a[stp].c) && c2<n/2) dfs(stp+1,sum+a[stp].b,c1,c2+1,c3);
	if((a[stp].c>=a[stp].a||a[stp].c>=a[stp].b) && c3<n/2) dfs(stp+1,sum+a[stp].c,c1,c2,c3+1);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		bool flg=1;
		for(ll i=1; i<=n; ++i) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c) flg=0;
		}
		if(flg) {
			sort(a+1,a+n+1,cmp);
			ans=0;
			for(ll i=1,cnt=0; i<=n; ++i)
				if(cnt<n/2) ++cnt,ans+=a[i].a;
				else ans+=a[i].b;
			cout<<ans<<"\n";
		} else ans=0,dfs(1,0,0,0,0),cout<<ans<<"\n";
	}
	return 0;
}
