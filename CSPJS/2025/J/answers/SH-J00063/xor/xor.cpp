#include <iostream>
#include <queue>
using namespace std;
int dp[500005],a[500005],maxx[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]^a[i];
	}
	maxx[1]=(dp[1]==k);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(dp[j]^dp[i]==k){
				maxx[i]=max(maxx[i],maxx[j]+1);	
			}
			if(dp[j]^dp[i]!=k){
				maxx[i]=max(maxx[i],maxx[j]);	
			}
		}
		
	}
	cout<<maxx[n];
	return 0;
}
