#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int plan[25];
int a[5005];
int c[5005][5005];
void build()
{
	c[0][0]=1;
	for(int i = 1; i <= n; i++)c[i][0]=c[i][i]=1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j < i; j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
	}
}
void dfs(int step)
{
	if(step>n)
	{
		int tot=0,maxn=0,cnt=0;
		for(int i = n; i >= 1; i--)
		{
			if(plan[i]==1)
			{
				cnt++;
				tot+=a[i];
				if(maxn==0)maxn=i;
			}
		}
		if(cnt>=3&&tot>a[maxn]*2)ans++;
		return ;
	}
	plan[step]=1;
	dfs(step+1);
	plan[step]=0;
	dfs(step+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1,a+n+1);
	if(n<=20)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	if(a[n]>1)return 0;
	build();
	for(int i = 3; i <= n; i++)ans=(ans+c[n][i])%998244353;
	cout << ans;
	return 0;
}
