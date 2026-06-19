#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod=998244353;
const int kMAX=505;

int n,m;
int s[505];
int c[505];
int dp[505][505];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool tA=true;
	for (int i=1;i<=n;i++){
		char x;
		cin>>x;
		int y=x-'0';
		s[i]=y;
		if (s[i]!=1)tA=false;
	}
	for (int i=1;i<=m;i++)cin>>c[i];
	if (tA){
		dp[0][0]=1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=n && j<=i;j++){
				dp[i][j]=dp[i-1][j];
				dp[i][j]%=mod;
				if (i-j<c[i] && j>=1)dp[i][j]+=dp[i-1][j-1];
				dp[i][j]%=mod;
			}
		}
		int ans=0;
		for (int i=m;i<=n;i++){
			ans+=dp[n][i];
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
