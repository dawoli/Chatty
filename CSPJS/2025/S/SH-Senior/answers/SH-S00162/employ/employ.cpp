#include<bits/stdc++.h>
using namespace std;
int dp[5][100005];
int n,m,mod=998244353;
string s;
int c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s; 
	for(int i=0;i<n;i++) {
		cin>>c[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++) {
		int cur=i%2;
		int prev=(i-1)%2;
		char d=s[i-1];
		int p=c[i-1];
		for(int j=0;j<=m;j++) {
			if((i-j-1)<=p) {
				dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			}
			if(j>=1&&d=='1') {
				dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%mod;
			}
		}
	}
	cout<<dp[n][m%2]<<endl;
	return 0;
}
