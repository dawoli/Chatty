#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long ans,a[5001],n;
void dfs(long long u,long long cnt,long long sum,long long mx) {
	if(u=n+1) if(cnt>=3&&sum>2*mx) ans=(ans+1)%M;
	if(sum<2*mx) return;
	dfs(u+1,cnt,sum,mx);
	if(mx!=max(mx,a[u])) dfs(u+1,cnt+1,sum,a[u]);
	else dfs(u+1,cnt+1,sum+a[u],mx);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i = 1; i<=n; i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

