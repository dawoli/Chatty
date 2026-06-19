/*
左边第一个同色的，如果数字相等，答案加上a[i]
只有两种颜色

部分分：35:n<=100
我们记dp[i][j][k]为现在到i，上一个红色点为j时，上一个蓝色点为k时，最大收益
35分拿下了

满分做法： 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn1=105;
const int maxn=2e5+5;
const int maxa=1e6+5;
int T,n,a[maxn],dp[maxn1][maxn1][maxn1],ans[maxn];
signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++)  cin>>a[i];
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) {
			for(int j=0;j<i;j++) {
				for(int k=0;k<i;k++) {
					if(j==k)  continue;
					if(j!=i-1&&k!=i-1)  continue;
					dp[i][i][k]=max(dp[i][i][k],dp[i-1][j][k]+(a[i]==a[j]?a[i]:0));
					dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]+(a[i]==a[k]?a[i]:0));
				}
			}
		}
		int res=0;
		for(int j=0;j<=n;j++)
		    for(int k=0;k<=n;k++)
			    res=max(res,dp[n][j][k]);
		cout<<res<<"\n";
	}
	return 0;
}
