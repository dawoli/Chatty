#include<bits/stdc++.h>
using namespace std;

long long t,n,m,k,x,y,d,ans,mv[4][2]={0,1,1,0,0,-1,-1,0},xx,yy;
char a[1055][1055];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		//cout<<t<<endl;
		ans=0;
		cin>>n>>m>>k;
		//cout<<1<<endl;
		cin>>x>>y>>d;
		//cout<<2<<endl;
		for(int i=1;i<=n;i++)
		{
			//cout<<3<<endl;
			for(int j=1;j<=m;j++)
			{
				//cout<<4<<endl;
				cin>>a[i][j];
			}
		}
		//cout<<5<<endl;
		a[x][y]='d';
		//cout<<6<<endl;
		//dfs();
		//cout<<x<<' '<<y<<endl;
		while(k)
		{
			xx=x+mv[d][0];
			yy=y+mv[d][1];
			//cout<<x<<' '<<y<<' '<<d<<' '<<k<<' '<<a[x][y]<<' '<<ans<<endl; 
			if(xx>n||xx<1||yy>m||yy<1||a[xx][yy]=='x')
			{
				d++;
				d%=4;
			}
			else
			{
				x+=mv[d][0];
				y+=mv[d][1];
				if(a[x][y]=='.')
				{
					ans++;
					a[x][y]='d';
				}
			}
			k--;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
