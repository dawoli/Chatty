#include <bits/stdc++.h>
using namespace std;
int ans;
int c[505],n,m,u[505];
char s[505];
void dfs(int dep,int x,int cnt)
{
	if (dep>n)
	{
		if (cnt>=m) ans++;
		return;
	}
	else
	{
		cnt++;
		if (s[x]=='1'&&dep-cnt<c[x])
		{
			cout<<x<<" "<<cnt<<endl;
		}
		else cnt--;
		u[x]=1;
		for (int i=1;i<=n;i++)
		{
			if (u[i]==0)
			{
				dfs(dep+1,i,cnt);
			}
		}
		u[x]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
		cout<<s[i]<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		dfs(1,i,0);
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
