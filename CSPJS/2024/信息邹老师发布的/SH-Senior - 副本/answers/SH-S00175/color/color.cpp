#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[200005], dp[200005], ma, add, maxx[1000005], maxnow;
//maxx[k]表示a[i]=k的dp[i]的最大值 
int main(){
	freopen("color.in","r",stdin); freopen("color.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>t;
	while(t){
		t--;
		memset(dp,0xc0,sizeof(dp));
		dp[0]=0;
		memset(maxx,0xc0,sizeof(maxx));
		ma=0, add=0, maxnow=-1e15;
		cin>>n;
		for(ll i=1; i<=n; i++) cin>>a[i];
		for(ll i=1; i<=n; i++){
			if(a[i]==a[i-1]){
				dp[i-1]=max(dp[i-1],max(maxnow,maxx[a[i]]+a[i]));
				dp[i-1]-=a[i];
				add+=a[i];
			}
			else{
				dp[i-1]=max(dp[i-1],max(maxnow,maxx[a[i]]+a[i]));
			}
			maxnow=max(maxnow,dp[i-1]);
			maxx[a[i-1]]=max(maxx[a[i-1]],dp[i-1]);
			maxx[a[i]]=max(maxx[a[i]],dp[i-1]);
		}
		for(ll i=0; i<n; i++) ma=max(ma,dp[i]); 
		cout<<ma+add<<'\n';
	}
	return 0;
}
/*
简单来说就是把一个数组分成两半，然后希望做到就是说两块的连续数都比较多就够了
先去把部分分拿下来 
*/ 
