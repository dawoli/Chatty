#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,res;
int x,y,d;
char c[1005][1005];
bool f[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=1005;++i)
		for(int j=1;j<=1005;++j)
			c[i][j]='.';
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=1005;++i)
			for(int j=1;j<=1005;++j)
				f[i][j]=0;
		f[x][y]=1,res=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>c[i][j];
		for(int i=1;i<=k;++i)
		{
			if(d==0)
			{
				if(y+1<=m && c[x][y+1]=='.')
				{
					 if(!f[x][y+1]) res++,f[x][y+1]=1;
					 y++;
				}
				else d=(d+1)%4;
			}
			else if(d==1)
			{
				if(x+1<=n && c[x+1][y]=='.')
				{
					 if(!f[x+1][y]) res++,f[x+1][y]=1;
					 x++;
				}
				else d=(d+1)%4;
			}
			else if(d==2)
			{
				if(y-1>=0 && c[x][y-1]=='.')
				{
					if(!f[x][y-1]) res++,f[x][y-1]=1;
					y--;
				}
				else d=(d+1)%4;
			}
			else if(d==3)
			{
				if(x-1>=0 && c[x-1][y]=='.')
				{
					if(!f[x-1][y]) res++,f[x-1][y]=1;
					x--;
				}
				else d=(d+1)%4;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
