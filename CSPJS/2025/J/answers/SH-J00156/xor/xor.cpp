#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],dp[N],sum[N];
map<int,int> mp;
int to[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k; 
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i],to[i]=-1;
	for(int i=1;i<=n;i++) mp[k^sum[i]]=-1;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		mp[sum[i]]=i;
		if(mp[k^sum[i]]!=-1) to[i]=mp[k^sum[i]];
	}
	for(int i=1;i<=n;i++){
		if(to[i]==-1) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[to[i]]+1);
	}
	cout<<dp[n]<<endl;
	return 0;
} 
