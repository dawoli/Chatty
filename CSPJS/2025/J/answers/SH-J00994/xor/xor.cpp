#include<bits/stdc++.h>
using namespace std;
int n,k,dp[500005][2],a[500005],b[500005],lst,c;
map<int,bool> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(dp[i-1][1]>dp[i-1][0]){
			dp[i][0]=dp[i-1][1];
			lst=i;
			b[i]=a[i];
			mp.clear();
		}
		else{
			dp[i][0]=dp[i-1][0];
			b[i]=b[i-1]^a[i];
		}
		if(b[i]==k)dp[i][1]=dp[i][0]+1;
		else{
			c=k^b[i];
			if(mp[c]){
				dp[i][1]=dp[i][0]+1;
			}
		}
		mp[b[i]]=1;
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
}
