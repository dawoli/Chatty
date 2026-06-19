#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,t,dir[4][2] = {0,1,1,0,0,-1,-1,0};
bool g[1001][1001],b[1001][1001];
char c;
int dfs(int x,int y,int d,int k,int ans)
{
	if(!k) return ans;
	b[x][y] = 1;
	int tx = x + dir[d][0],ty = y + dir[d][1];
	if(!g[tx][ty] && tx > 0 && tx <= n && ty > 0 && ty <= m)
	{
		if(!b[tx][ty]) return dfs(tx,ty,d,k-1,ans+1);
		else return dfs(tx,ty,d,k-1,ans);
	}
	else return dfs(x,y,((d+1)%4),k-1,ans);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int l = 1 ; l <= t ; l++)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				cin>>c;
				if(c == 'x') g[i][j] = 1;
				else g[i][j] = 0;
				b[i][j] = 0;
			}
		}
		cout<<dfs(x,y,d,k,1)<<endl;
	}
	return 0;
}
