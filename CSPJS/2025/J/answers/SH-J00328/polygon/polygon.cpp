#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5001];
long long ans;
void dfs(int x, int t, long long sum)
{
	if(x==1)
	{
		for(int i=t+1;i<n;i++)
		{
			if(a[i]<sum)
				ans++;
		}
		return;
	}
	for(int i=t+1;i<n;i++)
	{
		dfs(x-1,i,sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=3;i<=n;i++)
		dfs(i,-1,0);
	cout<<ans%998244353;
	return 0;
}
