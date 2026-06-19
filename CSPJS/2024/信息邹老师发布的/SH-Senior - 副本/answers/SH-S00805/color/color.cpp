#include <bits/stdc++.h>
using namespace std;
int t,n,a[200005],b[200005],c[200005],ans;
void check()
{
	memset(c,0,sizeof(c));
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(b[j]==1)
			{
				if(a[i]==a[j])
				{
					c[i]=a[i];
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=c[i];
	}
	ans=max(ans,sum);
}
void dfs(int step)
{
	if(step==n+1)
	{
		check();
		return;
	}
	for(int i=1;i<=2;i++)
	{
		b[step]=i;
		dfs(step+1);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
} 
