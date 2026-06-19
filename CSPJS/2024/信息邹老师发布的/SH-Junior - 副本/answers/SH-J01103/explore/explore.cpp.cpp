#include <iostream>
#include <cstdio>
using namespace std;
char b[1005][1005];
bool flag[1005][1005];
bool chk(int x,int y,int n,int m)
{
	if(x<1||x>n||y<1||y>m)return 0;
	else return 1; 
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d;
		cin>>x0>>y0>>d;
		for(int j=1;j<=1005;j++)
		{
			for(int l=1;l<=1005;l++)
			{
				flag[j][l]=0;
			}
		}
		flag[x0][y0]=1;
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				cin>>b[j][l]; 
			}
		}	 
		int nx=x0,ny=y0;
		while(k--)
		{
			if(d==0)
			{
				if(chk(nx,ny+1,n,m)==1&&b[nx][ny+1]!='x')ny++;
				else d=(d+1)%4;
			}
			else if(d==1)
			{
				if(chk(nx+1,ny,n,m)==1&&b[nx+1][ny]!='x')nx++;
				else d=(d+1)%4;
			}
			else if(d==2)
			{
				if(chk(nx,ny-1,n,m)==1&&b[nx][ny-1]!='x')ny--;
				else d=(d+1)%4;
			}
			else 
			{
				if(chk(nx-1,ny,n,m)==1&&b[nx-1][ny]!='x')nx--;
				else d=(d+1)%4;
			}
			flag[nx][ny]=1;
		}
		int cnt=0;
		for(int j=1;j<=1000;j++)
		{
			for(int l=1;l<=1000;l++)
			{
				if(flag[j][l]==1)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
