#include<bits/stdc++.h>
using namespace std;
#define int long long

int T;
int n,m,V,L,ans;
int d[100005],v[100005],a[100005],pos[100005];
bool vis[100005],is[100005];

void dfs(int step)
{
	if (step>m)
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (!is[i]) continue;
			bool flag=0;
			for (int j=1;j<=m;j++)
			{
				if (!vis[j])
				{
					continue;
				}
				int t=pos[j];
				if (d[i]>t) continue;
				int tv=ceil(sqrt(v[i]*v[i]+2*a[i]*(t-d[i])));
				if (tv>V)
				{
					flag=1;
					break;
				}
			}
			if (!flag) return;
		}
		for (int j=1;j<=m;j++)
		{
			if (!vis[j]) cnt++;
		}
		ans=max(ans,cnt);
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}

signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	int T;
	cin >> T;
	while (T--)
	{
		int flag1=1,flag2=1;
		cin >> n >> m >> L >> V;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if (a[i]!=0) flag1=0;
			if (a[i]<=0) flag2=0;
		}
		int maxn=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%lld",&pos[i]);
			maxn=max(maxn,pos[i]);
		}
		if (flag1)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (v[i]>V && d[i]<=maxn) cnt++;
			}
			cout << cnt << " " << m-1 << endl;
			continue;
		}
		else if (flag2)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (maxn<d[i]) continue;
				if (v[i]*v[i]+2*a[i]*(maxn-d[i])>V*V)
				{
					cnt++;
				}
			}
			cout << cnt << " " << m-1 << endl;
			continue;
		}
		memset(is,0,sizeof(is));
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				int t=pos[j];
				if (d[i]>t) continue;
				if (v[i]*v[i]+2*a[i]*(t-d[i])>V*V)
				{
					cnt++;
					is[i]=1;
					break;
				}
			}
		}
		cout << cnt << " ";
		ans=0;
		dfs(1);
		cout << ans << endl;
	}
	
	
	
	return 0;
}
