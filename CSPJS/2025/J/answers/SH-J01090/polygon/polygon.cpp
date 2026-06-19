#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int MAXN=5e3+5;
int n;
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int dp[MAXN][MAXN];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	dp[n][0]=1;
	dp[n][a[n]]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=5001;j++){
			dp[i+1][j]+=dp[i+2][j];
			dp[i+1][min(5001ll,j+a[i+1])]+=dp[i+2][j];
			dp[i+1][j]%=MOD;
			dp[i+1][min(5001ll,j+a[i+1])]%=MOD;
		}
		for(int j=a[i]+1;j<=5001;j++){
			ans+=dp[i+1][j];
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
