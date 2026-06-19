#include<bits/stdc++.h>
using namespace std;
namespace SoaringWings
{
int v,n;
vector<int> w,dp(0);
void Soar()
{
	cin>>v>>n;
	w.resize(n+1);
	dp.resize(v+1);
	for(int i=1;i<=n;i++)cin>>w[i];
	for (int i = 1; i <= n; i++)
		for (int l = v; l >= w[i]; l--)
			if (dp[l - w[i]] + w[i] > dp[l]) dp[l] = dp[l - w[i]] + w[i]; 
	cout<<v-dp[v];
	return;
}
}
int main()
{
	SoaringWings::Soar();
	return 0;
}
