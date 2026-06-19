#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d; 
long long ans=1;
char a[1005][1005];
bool flag[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) 
			{
				cin>>a[i][j];
			}
		}
		flag[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int xx=x,yy=y;
			if(d==0) yy++;
			if(d==1) xx++;
			if(d==2) yy--;
			if(d==3) xx--;
			if(xx>0 && xx<=n && yy>0 && yy<=m && a[xx][yy]=='.')
			{
				x=xx;
				y=yy;
				if(flag[x][y]==0) 
				{
					flag[x][y]=1;
					ans++;
				}
			}
			else 
			{
				d=(d+1)%4;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) flag[i][j]=0;
		}
	}
	return 0;
}
