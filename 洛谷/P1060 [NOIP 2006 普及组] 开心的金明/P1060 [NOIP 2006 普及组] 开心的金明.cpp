#include<bits/stdc++.h>
using namespace std;
namespace SoaringWings
{
	int n,m;
	vector<int> v,w,dp(0);
	void Soar()
	{
		cin>>n>>m;
		v.resize(m+1);
		w.resize(m+1);
		dp.resize(n+1);
		for(int i=1;i<=m;i++)cin>>v[i]>>w[i];
		for (int i = 1; i <= m; i++)
		{
			for (int l = n; l >= v[i]; l--)
			{
				if (dp[l - v[i]] + v[i]*w[i] > dp[l])
				{
					dp[l] = dp[l - v[i]] + v[i]*w[i]; 
				}
			}
		}
		cout<<dp[n];
		return;
	}
}
int main()
{
	SoaringWings::Soar();
	return 0;
}
