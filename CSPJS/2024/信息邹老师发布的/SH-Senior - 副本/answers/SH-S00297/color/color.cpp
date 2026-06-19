#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005;
ll n,dp[N][N][3],t,a[N],maxn;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll k=1;k<i;k++){
				ll x=0;
				if(a[i]==a[i-1]) x=1;
				dp[i][k][1]=max(dp[i-1][k][1]+x*a[i],dp[i][k][1]);
				dp[i][k][0]=max(dp[i-1][k][0]+x*a[i],dp[i][k][0]);
				maxn=max(maxn,dp[i][k][1]);
				maxn=max(maxn,dp[i][k][0]);
			}
			for(ll j=1;j<i;j++){
				ll x=0;
				if(a[i]==a[j]) x=1;
				dp[i][i-1][1]=max(dp[i-1][j][0]+x*a[i],dp[i][i-1][1]);
				dp[i][i-1][0]=max(dp[i-1][j][1]+x*a[i],dp[i][i-1][0]);
				maxn=max(maxn,dp[i][i-1][1]);
				maxn=max(maxn,dp[i][i-1][0]);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
