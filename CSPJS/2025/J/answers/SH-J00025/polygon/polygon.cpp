#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5005,mod=998244353;
int n,a[N],ans;

void dfs(int x,int sum,int mx){
	if(x==n){
		if(sum>2*mx) ans=(ans+1)%mod;
		return ;
	}
	dfs(x+1,sum+a[x+1],max(mx,a[x+1]));
	dfs(x+1,sum,mx);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
