#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
#define V 20
bool d[N][V],vis[N][V];
int a[N],s[N],e[N],b[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		int n,kk,t,c=0;
		cin>>n>>kk>>t;
		s[1]=1;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			s[i]=e[i-1]+1;
			e[i]=s[i]+l-1;
			for(int j=1;j<=l;j++)
			{
				int x;
				cin>>x;
				a[++c]=x;
				b[c]=i;
			}
		}
		for(int i=1;i<=c;i++)
		{
			for(int j=max(s[b[i]],i-kk+1);j<=i-1;j++)
			{
				if(a[j]==1)
				{
					d[i][1]=1;
					break;
				}
			}
		}
		for(int i=1;i<=10;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(d[j][i]==0) continue;
				vis[a[j]][i]=1; 
				if(i==10) continue;
				for(int k=1;k<=c;k++)
				{
					if(b[j]==b[k]) continue;
					for(int l=max(s[b[k]],k-kk+1);l<=k-1;l++)
					{
						if(a[j]==a[l])
						{
							d[k][i+1]|=d[j][i];
							break;
						}
					}
				}
			}
		}
		while(t--)
		{
			int r,x;
			cin>>r>>x;
			if(vis[x][r]) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}

