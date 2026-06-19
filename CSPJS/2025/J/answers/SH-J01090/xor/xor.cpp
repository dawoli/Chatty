#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int pre[MAXN];
map<int,set<int> > mp;
int nxt[MAXN];
int dp[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
		mp[pre[i]].insert(i);
	}
	for(int i=1;i<=n;i++){
		int xor_val=pre[i-1]^k;
		set<int>::iterator index=mp[xor_val].lower_bound(i);
		if(index==mp[xor_val].end()) nxt[i]=n+1;
		else nxt[i]=*index;
	}
	for(int i=n;i>=1;i--){
		dp[i]=dp[i+1];
		if(nxt[i]!=n+1) dp[i]=max(dp[i],dp[nxt[i]+1]+1);
	}
	cout<<dp[1]<<endl;
	return 0;
}
