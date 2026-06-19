#include <bits/stdc++.h>
using namespace std;
int t;
long long n,m,k,ans,xi,yi,di;
char p[1005][1005];
bool tf[1005][1005],flag[1005][1005];
void f(int x,int y,int n,int m,int d,int k)
{
	flag[x][y]=1;
	if(k>0)
	{
		if((d==0&&y<=m-1&&tf[x][y+1]==0)||(d==1&&x<=m-1&&tf[x+1][y]==0)||(d==2&&y>=2&&tf[x][y-1]==0)||(d==3&&x>=2&&tf[x-1][y]==0))
		{
			if(d==0)
			{
				f(x,y+1,n,m,d,k-1);
			}
			if(d==1)
			{
				f(x+1,y,n,m,d,k-1);
			}
			if(d==2)
			{
				f(x,y-1,n,m,d,k-1);
			}
			if(d==3)
			{
				f(x-1,y,n,m,d,k-1);
			}
		}
		else
		{
			f(x,y,m,n,(d+1)%4,k-1);
		}
	}
	else return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>xi>>yi>>di;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>p[i][j];
				if(p[i][j]=='.') tf[i][j]=0;
				else if(p[i][j]=='x') tf[i][j]=1;
			}
		}
		f(xi,yi,n,m,di,k);
		for(int h=1;h<=n;h++)
		{
			for(int g=1;g<=m;g++)
			{
				if(flag[h][g]==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
