#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt[500005];
map<int,int> dp[500005];
void js(int i,int j)
{
	int ans=cnt[i-1]^cnt[j];
	if(ans==k) dp[i][j]=max(dp[i][j],1);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>a[i];
		cnt[i]=cnt[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			js(1,i);js(1,j);js(j+1,i);
			dp[1][i]=max(dp[1][i],dp[1][j]+dp[j+1][i]);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
