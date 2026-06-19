#include<bits/stdc++.h>
using namespace std;
bool card[1005][1005][2];
int n,m,x,y,d,k;
void fun()
{
	int x_=x,y_=y;
	if(d==0)
		y_++;
	else if(d==1)
		x_++;
	else if(d==2)
		y_--;
	else
		x_--;
	if(1<=x_&&x_<=n&&1<=y_&&y_<=m&&card[x_][y_][0])
	{
		x=x_;
		y=y_;
	}
	else
		d=(d+1)%4;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	for(long long i=0;i<t;i++)
	{
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int ix=1;ix<=n;ix++)
			for(int iy=1;iy<=m;iy++)
			{
				char tc;
				scanf("%c",&tc);
				if(tc=='x')
					card[ix][iy][0]=false;
				else
					card[ix][iy][0]=true;
				card[ix][iy][1]=false;
			}
		for(int j=0;j<=k;j++)
		{
			card[x][y][1]=true;
			fun();
		}
		int sum=0;
		for(int ix=1;ix<=n;ix++)
			for(int iy=1;iy<=m;iy++)
				if(card[x][y][1])
					sum++;
		printf("%d\n",sum);
	}
	return 0;
}
