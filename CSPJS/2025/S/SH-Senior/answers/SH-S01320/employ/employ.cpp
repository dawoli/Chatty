#include<bits/stdc++.h>
#define int long long
#define add(x,y) x=(x+y)%p
using namespace std;
const int p=998244353;
int f[2][505][505],c[505],g[505][505];
char s[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		c[x]++;
	}
	for(int i=1;i<=n;i++)c[i]+=c[i-1];
	bool cur=0,old=1;
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		swap(cur,old);
		memset(f[cur],0,sizeof(f[cur]));
		for(int j=0;j<i;j++)
		{
			for(int k=c[j];k<=c[j+1];k++)memset(g[k],0,sizeof(g[k]));
			for(int k=0;k<i;k++)
			{
				//add(g[c[j]+1][k],f[i-1][j][k]*(c[j+1]-c[j]));
				add(g[c[j]][k],f[old][j][k]*max(0ll,c[j]-(i-1-k)));
			}
			for(int k=c[j];k<c[j+1];k++)
			{
				for(int l=0;l<i;l++)
				{
					add(g[k+1][l],g[k][l]);
					if(l)add(g[k+1][l-1],g[k][l]*l);
				}
			}
			for(int k=0;k<i;k++)add(f[cur][j+1][k],g[c[j+1]][k]);
			if(s[i]=='0')
			{
				for(int k=c[j];k<=c[j+1];k++)memset(g[k],0,sizeof(g[k]));
				for(int k=0;k<i;k++)
				{
					add(g[c[j]+1][k],f[old][j][k]*(c[j+1]-c[j]));
				}
				for(int k=c[j];k<c[j+1];k++)
				{
					for(int l=0;l<i;l++)
					{
						add(g[k+1][l],g[k][l]);
						if(l)add(g[k+1][l-1],g[k][l]*l);
					}
				}
				for(int k=0;k<i;k++)add(f[cur][j+1][k],g[c[j+1]][k]);
				for(int k=c[j];k<=c[j+1];k++)memset(g[k],0,sizeof(g[k]));
				for(int k=0;k<i;k++)
				{
					add(g[c[j]][k],f[old][j][k]);
				}
				for(int k=c[j];k<c[j+1];k++)
				{
					for(int l=0;l<i;l++)
					{
						add(g[k+1][l],g[k][l]);
						if(l)add(g[k+1][l-1],g[k][l]*l);
					}
				}
				for(int k=0;k<i;k++)add(f[cur][j+1][k+1],g[c[j+1]][k]);
			}
			else
			{
				for(int k=0;k<i;k++)
				{
					add(f[cur][j][k+1],f[old][j][k]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
	{
		for(int j=c[i];j<=n;j++)memset(g[j],0,sizeof(g[j]));
		for(int k=0;k<=n;k++)
		{
			add(g[c[i]][k],f[cur][i][k]);
		}
		for(int j=c[i]+1;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				add(g[j][k],g[j-1][k]);
				if(k)add(g[j][k-1],g[j-1][k]*k);
			}
		}
		add(ans,g[n][0]);
	}
	cout<<ans;
}
