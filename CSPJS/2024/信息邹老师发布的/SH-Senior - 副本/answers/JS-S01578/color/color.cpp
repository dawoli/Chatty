#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005]={};
int l[200005]={};
long long dp[200005]={};
int mp[1000005]={};
void solve(){
	long long mx=0;
	long long cnt=0;
	for(int i=1;i<=1000000;i++){
		mp[i]=0;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dp[i-1]=mx;
		if(l[i]==0)continue;
		if(l[i]==i-1){
			cnt+=a[i];
			dp[i-1]-=a[i];
		}else{
			dp[i-1]=max(dp[i-1],dp[l[i]]+a[i]);
		}
		mx=max(mx,dp[i-1]);
	}long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}cout<<ans+cnt<<'\n';
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
