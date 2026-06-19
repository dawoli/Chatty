#include <bits/stdc++.h>
#define lol long long
#define ull unsigned long long
using namespace std;

int vis[200005];
lol a[200005];
lol c[200005];
lol maxn = -1e18;
lol n;
void dfs(int depth)
{
	//cout<<depth - 1<<' '<<vis[depth - 1]<<'\n';
	if(depth == n + 1)
	{
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i - 1;j >= 1;j --)
			{
				if(vis[i] == vis[j] && a[i] == a[j])
				{
					c[i] = a[i];
					break;
				}
				else if(vis[i] == vis[j]) break;
			}
		}
		lol sum = 0;
		for(int i = 1;i <= n;i ++)
		{
			sum += c[i];
		}
		//cout<<"sum:"<<sum<<'\n';
		maxn = max(maxn,sum);
		return ;
	}
	vis[depth] = 1; 
	//cout<<;
	dfs(depth + 1);	
	vis[depth] = 0;
//	cout<<666;
	dfs(depth + 1);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	lol t;
	cin>>t;
	while(t --)
	{
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		maxn = -1e18;
		
		cin>>n;
		
		//bool vis[200005];
		//1 L 2 H 
		for(int i = 1;i <= n;i ++)
		{
			cin>>a[i];
		}
		dfs(1);
		cout<<maxn<<'\n'; 
	}
	return 0;
}
