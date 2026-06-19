#include <bits/stdc++.h>
using namespace std;
char p[1005][1005];
int t,b[10];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m,k,x,y,d,s=0,a=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>p[i][j];
			}
		}
		while(a<k)
		{
			if(d==0&&y+1<=m&&p[x][y+1]!='x')
			{
				s++;
				y+=1;
				a++;
				continue;
			}
			else
			{
				d=(d+1)%4;
				a++;
				continue;
			}
			if(d==1&&x+1<=n&&p[x+1][y]!='x')
			{
				s++;
				x+=1;
				a++;
				continue;
			}
			else
			{
				d=(d+1)%4;
				a++;
				continue;
			}
			if(d==2&&y-1>=1&&p[x][y-1]!='x')
			{
				s++;
				y-=1;
				a++;
				continue;
			}
			else
			{
				d=(d+1)%4;
				a++;
				continue;
			}
			if(d==3&&x-1>=1&&p[x-1][y]!='x')
			{
				s++;
				x-=1;
				a++;
				continue;
			}
			else
			{
				d=(d+1)%4;
				a++;
				continue;
			}
		}
		b[i]=s+1;
	}
	for(int i=1;i<=t;i++)
		cout<<b[i]<<endl;
	return 0;
}
