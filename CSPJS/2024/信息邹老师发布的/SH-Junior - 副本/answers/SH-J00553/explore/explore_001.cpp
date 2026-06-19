#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,ans=1,x,y,d,k;
bool map0[1001][1001]={0},map1[1001][1001]={0};
char a;
int main()
{
    freopen ("explore.in","r",stdin);
    freopen ("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans =1;
		
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(int j=1;j<=n;j++)
		for(int j1=1;j1<=m;j1++)
		{
			map0[j][j1]=0;
			map1[j][j1]=0;
		}
		map1[x][y]=true;
		for(int j=1;j<=n;j++)
		for(int j1=1;j1<=m;j1++)
		{
			cin>>a;
			if(a=='x') map0[j][j1]=1;
		}
		while(k>0)
		{
			int X,Y;
			k--;
			X=x;
			Y=y;
			if(d==0) Y++;
			if(d==1) X++;
			if(d==2) Y--;
			if(d==3) X--;
			if(map0[X][Y] || X==0 || X==n+1 || Y==0 || Y==m+1) d=(d+1)%4;
			else
			{
				x=X;
				y=Y;
				if(!map1[x][y])
				{
					map1[x][y]=1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
