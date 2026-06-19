#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int a[N];
int vis[N];//0≤ª”√, 1”√ 
int n;

bool check()
{
	int shiyong_sum = 0;
	int maxx = 2*a[n];
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i] == 1)
		{
			shiyong_sum+=1;
			sum += a[i];
		}
	}
	if(shiyong_sum <= 2)
	{
		return false;
	}
	if(sum <= maxx)
	{
		return false;
	}
	return true;
}

void dfs(int step,long long sum)
{
	if(step == n+1)
	{
		if(check)
		{
			sum++;
		}
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		vis[i] = 0;
		dfs(step+1,sum);
		vis[i] = 1;
		dfs(step+1,sum);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,sum);
	cout<<sum % 998244353;
	return 0;
}
