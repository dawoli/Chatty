#include <bits/stdc++.h>
const int mox[4]={0,1,0,-1},moy[4]={1,0,-1,0};
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int m,n,k;
	for (int i=1;i<=t;i++)
	{
		cin>>m>>n>>k;
		int d=4,x0=0,y0=0,x2=0,y2=0,ans=1;
		char bl[1001][1001]={},map[1001][1001]={};
		cin>>x0>>y0>>d;
		bl[x0][y0]=1;
		for (int j=1;j<=m;j++)
			for (int j1=1;j1<=n;j1++)
				cin>>map[j][j1];
		for (int j=1;j<=k;j++)
		{
			x2=x0+mox[d];
			y2=y0+moy[d];
			if((x2>0)&&(x2<=m)&&(y2>0)&&(y2<=n)&&map[x2][y2]=='.')
			{
				x0=x2;
				y0=y2;
				if (bl[x0][y0]==0)
				{
					bl[x0][y0]=1;
					ans++;
				}
			}
			else
			{
				d=(d+1)%4; 
				x2=x0;
				y2=y0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
