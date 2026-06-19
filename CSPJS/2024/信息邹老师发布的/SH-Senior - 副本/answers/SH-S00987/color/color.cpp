#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100],n,vis[100],ans;
void dfs(int step)
{
	if (step>n)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i-1;j>=1;j--)
			{
				if (vis[j]==vis[i])
				{
					if (a[i]==a[j])
					{
						sum+=a[i];
					}
					break;
				}
			}
		}
		ans=max(ans,sum);
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}

signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		if (n>15)
		{
			cout << 0 << endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		ans=0;
		dfs(1);
		cout <<ans << endl;
	}
	
	return 0;
}
