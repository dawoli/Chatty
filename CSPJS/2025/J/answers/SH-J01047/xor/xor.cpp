#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=1e6+10;

int a[N];
int dp[N];
int sum[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==k){
			dp[i]=1;
		}
		else dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if((sum[i]^sum[j])==k){
				dp[i]=max(dp[i],dp[j]+1ll);
				//else dp[i]=max(dp[i],1ll);
			}
			else dp[i]=max(dp[i],dp[i-1]);
		}
		//if(a[i]=='0') continue;
	}
	/*for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}*/
	cout<<dp[n]<<endl;
}
