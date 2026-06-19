#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
struct node{
	int l,r;
};
int dp[500005];
int sum[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			sum[i]=sum[i-1]^t;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				int t=sum[i]^sum[j-1];
				if(t!=k)continue;
				cout<<j<<' '<<i<<endl;
				dp[i]=max(dp[i],1);
				for(int l=1;l<j;l++){
					//cout<<dp[l]+1<<' '<<dp[i]<<endl;
					dp[i]=max(dp[i],dp[l]+1);
				}
				ans=max(ans,dp[i]);
			}
		}
		cout<<ans;
	}
	else {
		vector<node> v;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			sum[i]=sum[i-1]^t;
			for(int j=i;j>=1;j--){
				int t=sum[i]^sum[j-1];
				if(t!=k)continue;
				v.push_back({j,i});
				break;
			}
		}
		int la=0,ans=0;
		for(int i=0;i<v.size();i++){
			if(v[i].l>la){
				ans++;
				la=v[i].r;
			}
		}
		cout<<ans;
	}
	return 0;
} 
