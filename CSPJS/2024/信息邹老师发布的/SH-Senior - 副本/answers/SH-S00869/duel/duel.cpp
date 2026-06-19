#include<iostream>
using namespace std;
const int N=1e5+5;
int n;
int dp[N],a[N],maxn;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]++;
		maxn=max(maxn,x);
	}
	dp[1]=a[1];
	for(int i=2;i<=maxn;i++)
	{
		dp[i]=max(dp[i-1],a[i]);
	}
	cout<<dp[maxn]<<endl;
	return 0;
}
