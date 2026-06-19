#include<bits/stdc++.h>

using namespace std;

int t,n,m,l,v;

struct node
{
	int di,ai,vi;
};

node x[3050];

int ans;

int ono[3050];

int cnt[3050];

int vis[3050][3050];

int vst[3050];

int p[3050];

int plan[3050];

void dfs(int step,int num)
{
	if(num > ans)return ;
	if(step > m)
	{
		memset(vst,0,sizeof(vst));
		for(int i = 1;i <= m;i++)
		{
			if(plan[i] == 1)
			{
				for(int j = 1;j <= cnt[i];j++)
				{
					vst[vis[i][j]] = 1;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			if(ono[i] == 1)
			{
				if(vst[i] == 0)
				{
					return ;
				}
			}
		}
		ans = min(ans,num);
		return ;
	}
	plan[step] = 1;
	dfs(step+1,num+1);
	plan[step] = 0;
	dfs(step+1,num);
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(ono,0,sizeof(ono));
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&x[i].di,&x[i].vi,&x[i].ai);
		}
		for(int i = 1;i <= m;i++)
		{
			scanf("%d",&p[i]);
		}
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(x[i].ai >= 0 && x[i].vi > v)
			{
				if(p[m] < x[i].di)continue;
				ans++;
				ono[i] = 1;
				int pos = lower_bound(p+1,p+m+1,x[i].di)-p;
				for(int j = pos;j <= m;j++)
				{
					vis[j][++cnt[j]] = i;
				}
				continue;
			}
			if(x[i].ai == 0)continue;
			if(x[i].ai > 0)
			{
				int dis = (v*v-x[i].vi*x[i].vi)/(2*x[i].ai);
				int pos2 = upper_bound(p+1,p+m+1,x[i].di+dis)-p;
				if(x[i].di+dis > p[m])
				{
					pos2 = m+1;
					continue;
				}
				ans++;
				for(int j = pos2;j <= m;j++)
				{
					vis[j][++cnt[j]] = i;
				}
				continue;
			}
			int dis = (v*v-x[i].vi*x[i].vi)/(2*x[i].ai);
			int pos1 = lower_bound(p+1,p+m+1,x[i].di)-p;
			int pos2 = lower_bound(p+1,p+m+1,x[i].di+dis)-p;
			if(x[i].di+dis > p[m])
			{
				pos2 = m+1;
			}
			if(pos1 < pos2)
			{
				ans++;
				ono[i] = 1;
			}
			for(int j = pos1;j < pos2;j++)
			{
				vis[j][++cnt[j]] = i;
			}
		}
		cout<<ans<<" ";
		ans = m;
		dfs(1,0);
		cout<<m-ans<<"\n";
	}
	return 0;
} 
