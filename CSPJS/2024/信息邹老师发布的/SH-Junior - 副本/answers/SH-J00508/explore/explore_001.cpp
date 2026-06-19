#include<bits/stdc++.h>
using namespace std;
int xm[4]={0,1,0,-1};
int ym[4]={1,0,-1,0};
char map1[1001][1001];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d,sum=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		sum=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)
		{
			for(int r=1;r<=m;r++)
			{
				cin>>map1[j][r];
			}
		}
		map1[x][y]=y;
		while(k)
		{
			if((x+xm[d])>=1&&(x+xm[d])<=n&&(y+ym[d])>=1&&(y+ym[d])<=m&&map1[x+xm[d]][y+ym[d]]!='x')
			{
				x+=xm[d];
				y+=ym[d];
				if(map1[x][y]!='y')
				{
					map1[x][y]='y';
					sum++;
				}
				k--;
			}
			else
			{
				d=(d+1)%4;
				k--;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
