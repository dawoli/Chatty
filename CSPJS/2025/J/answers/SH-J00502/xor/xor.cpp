#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define db double
using namespace std;
const int N=5e5;
int dp[N+10];
map<int,int> mp1;
map<int,bool> mp2;
int n,k,ans=0;
int a[N+10];
int xora[N+10];
void work(int v1,int v2)
{
	mp2[xora[v1]]=1;
	mp1[xora[v1]]=v2;
	ans=v2;
	return;
}
int work2(int v1)
{
	return mp2[v1]? 0:1;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		xora[i]=a[i]^xora[i-1];
	}
	work(0,0);
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		dp[i]=max(mp1[xora[i]^k]+1-work2(xora[i]^k),dp[i]);
		work(i,dp[i]);
	}
	cout<<ans;
	return 0;
}
