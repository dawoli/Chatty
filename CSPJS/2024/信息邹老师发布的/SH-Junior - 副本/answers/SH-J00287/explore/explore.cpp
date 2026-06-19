#include <bits/stdc++.h>
using namespace std;
long long a[1010][1010]; 
long long vis[1010][1010];
char s;
long long n,m,k;
long long x,y,d;
long long t;
long long ans;
int main ( ){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int f=0;f<t;f++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>s;
				vis[i][j]=0;
				if(s=='x')
					a[i][j]=-1;
				else
					a[i][j]=0;
			}
		vis[x][y]=1;
		for(int i=0;i<k;i++)
		{
			long long xx,yy;
			if(d==0)
				xx=x,yy=y+1;
			else if(d==1)
				xx=x+1,yy=y;
			else if(d==2)	
				xx=x,yy=y-1;
			else 
				xx=x-1,yy=y;
			bool f=false;
			if((1<=xx&&xx<=n)&&(1<=yy&&yy<=m))
				if(a[xx][yy]==0)
					f=true;
			if(f==true)
			{
				if(vis[xx][yy]==0)
						ans++,vis[xx][yy]=1;
				x=xx;
				y=yy;
			}
			else
			{
				d++;
				d%=4;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
