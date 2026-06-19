#include<bits/stdc++.h>
using namespace std;

int n;
int a[5003];
bool use[5003];
long long ans;

void dfs(int step,int m,long long sum,long long max);

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans/2;
	return 0;
}

void dfs(int step,int m,long long sum,long long max)
{
	if (step>n)return;
	long long maxx = max;
	if (a[step]>maxx)maxx = a[step];
	if ((m>=3) && ((sum+a[step])>(maxx*2)))
	{
		ans = (ans+3)%(998244353*3);
		for(int i = 1;i<=n;i++)if(use[i])cout<<i<<' ';
	}
	dfs(step+1,m+1,sum+a[step],maxx);//choose cur
	dfs(step+1,m,sum,max);//skip cur
}
