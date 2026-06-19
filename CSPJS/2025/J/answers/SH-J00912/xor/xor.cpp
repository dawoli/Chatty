#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N];
long long dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(long long j=i;j>=1;j--)
		{
			if((a[i]^a[j-1])==m)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

