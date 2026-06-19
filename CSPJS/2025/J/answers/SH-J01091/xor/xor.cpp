#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,cnt,x;
int arr[MAXN],p[MAXN],dp[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		p[i]=p[i-1]^arr[i];
	}
	for(int i=1,ii=i;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(p[j]^p[ii-1]==k)
			{
				dp[i]++;
				ii=j,j++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(dp[i],ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
