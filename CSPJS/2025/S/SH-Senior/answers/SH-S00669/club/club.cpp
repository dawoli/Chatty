#include <bits/stdc++.h>
using namespace std;
int a[100005][5],t,u[5],ans,n;
void dfs(int dep,int sum)
{
	if (dep>n)
	{
		ans=max(ans,sum);
		return;
	}
	else
	{
		if (u[1]<n/2)
		{
			u[1]++;
			dfs(dep+1,sum+a[dep][1]);
			u[1]--;
		}
		if (u[2]<n/2)
		{
			u[2]++;
			dfs(dep+1,sum+a[dep][2]);
			u[2]--;
		}
		if (u[3]<n/2)
		{
			u[3]++;
			dfs(dep+1,sum+a[dep][3]);
			u[3]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t>0)
	{
		t--;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<endl;
		ans=0;
		memset(u,0,sizeof(u));
	}
	return 0;
}
