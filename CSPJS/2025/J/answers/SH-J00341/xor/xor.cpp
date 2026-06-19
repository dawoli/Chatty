#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1100000
int n,k,a[N],l[N],now,dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	memset(l,-1,sizeof(l));
	l[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		now^=a[i];
		dp[i]=dp[i-1];
		if(l[now^k]!=-1){
			dp[i]=max(dp[i],dp[l[now^k]]+1);
		}
		l[now]=i;
	}
	cout<<dp[n]<<'\n';
	return 0;
}
