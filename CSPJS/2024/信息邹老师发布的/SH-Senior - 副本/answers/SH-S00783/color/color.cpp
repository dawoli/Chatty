#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef __int128 lll;
int a[200000];
ll dp[2001][2002][2][2];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i];
		dp[1][0][0][0]=dp[1][0][1][1]=(a[1]==a[0]?a[1]:0);
		dp[1][0][0][1]=dp[1][0][1][0]=0;
		for(int i=1;i<n;++i){
			for(bool b1:{0,1}){
				for(bool b2:{0,1}){
					dp[i][n+1][b1][b2]=0;
					for(int j=0;j<i-1;++j){
						if(b1!=b2){
							if(j==0) dp[i][j][b1][b2]=ll(a[i]==a[j]?a[i]:0);
							else dp[i][j][b1][b2]=max(dp[j][n+1][b1][!b2],dp[j][n+1][!b1][!b2])+(a[i]==a[j]?a[i]:0);
						}
						else{
							if(j<i-2) dp[i][j][b1][b2]=dp[i-1][j][b1][b2]+(a[i]==a[i-1]?a[i]:0);
							else dp[i][j][b1][b2]=dp[i-1][n+2][!b1][b2]+(a[i]==a[i-1]?a[i]:0);
						}
						if(dp[i][n+1][b1][b2]<dp[i][j][b1][b2])
							dp[i][n+1][b1][b2]=dp[i][j][b1][b2];
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<n-2;++i){
			ll x1=max(dp[n-1][i][0][1],dp[n-1][i][0][0]);
			ll x2=max(dp[n-1][i][1][1],dp[n-1][i][1][0]);
			ll x=max(x1,x2);
			if(x>ans)
				ans=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
