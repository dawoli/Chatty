#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip> 
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k,result=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		char a[1001][1001]={0};
		bool b[1001][1001]={false};
		getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=getchar();
			}
			getchar();
		}
		b[x][y]=true;
		result=1;
		for(int i=1;i<=k;i++)
		{
			x+=xx[d];
			y+=yy[d];
			if(x<=n&&x>=1&&y<=m&&y>=1&&a[x][y]=='.')
			{
				if(b[x][y]==false)
				{
					b[x][y]=true; 
					result++;
				}
			}
			else
			{
				x-=xx[d];
				y-=yy[d];
				d=(d+1)%4;
			} 
		}
		cout<<result<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
