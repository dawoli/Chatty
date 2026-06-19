#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn=1000005;

int color[maxn];
int a[maxn];
int ans, n;
void check()
{
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		int t=-1;
		for(int j=1;j<i;j++)
		{
			if (color[i] == color[j] && a[i]==a[j]) t=j;
		}
		if (t != -1)
		{
			cur += a[t];
		}
	}
//	for(int i=1;i<=n;i++)cout<<color[i]<<' ';
//	cout<<cur<<endl;
	ans = max(ans, cur);
}
void dfs(int i)
{
	if (i>n)
	{
		check();
		return;
	}
	else
	{
		dfs(i+1);
		color[i]=1;
		dfs(i+1);
		color[i]=0;
	}
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int ttt;
	cin>>ttt;
	while(ttt--)
	{
		ans=0;
		memset(a, 0, sizeof(a));
		memset(color, 0, sizeof(color));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

