#include <iostream>
#include <conio.h>
using namespace std;
int f[1005][1005],T,n,m,k,x,y,d,ans;
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		f[x][y]=1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
		while(k--)
		{
			if(d==0)
			{
				if(a[x][y+1]=='.')
				{
					y++;
					f[x][y]=1;
				}
				else d=1;
			}
			else if(d==1)
			{
				if(a[x+1][y]=='.')
				{
					x++;
					f[x][y]=1;
				}
				else d=2;
			}
			else if(d==2)
			{
				if(a[x][y-1]=='.')
				{
					y--;
					f[x][y]=1;
				}
				else d=3;
			}
			else if(d==3)
			{
				if(a[x-1][y]=='.')
				{
					x--;
					f[x][y]=1;
				}
				else d=0;
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(f[i][j]==1)
		{
			ans++;
			f[i][j]=0;
		}	
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
