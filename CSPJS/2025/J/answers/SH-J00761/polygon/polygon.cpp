#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000005];
int n;
long long mod=998244353;
long long ssum=0,ans=0;
inline void dfs(int step,long long sum,int maxn)
{
	if (maxn*2>ssum) return;
	if (step>n)
	{
		if (sum>maxn*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(step+1,sum+a[step],max(maxn,a[step]));
	dfs(step+1,sum,maxn);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		ssum+=a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
