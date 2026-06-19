#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int sum;
int T;
int n,m,k;
int x,y,d;
void f(int d)
{
	if (d==0)
	{
		y+=1;
	}
	else if (d==1)
	{
		x+=1;
	}
	else if (d==2)
	{
		y-=1;
	}
	else if (d==3)
	{
		x-=1;
	}
}
void pd(int xx,int yy,int e)
{
	if ((1<=xx)&&(xx<=n)&&(1<=yy)&&(yy<=m)&&(a[xx][yy]=='.'))
	{
		//cout <<(1<=y)<<endl;
		//cout <<x << " " << y << endl;
		//cout << "x:" << xx << " y:" << yy << " d:" << e <<endl;
		b[xx][yy]=1;
	}
	else
	{
		if (e==0)
		{
			y--;
		}
		else if (e==1)
		{
			x--;
		}
		else if (e==2)
		{
			y++;
		}
		else if (e==3)
		{
			x++;
		}
		d=(e+1)%4;
		//cout <<x << " "<<y <<endl;
		b[x][y]=1;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for (int i = 1;i<=T;i++)
	{
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int w1=0;w1<=1004;w1++)
		{
			for (int w2=0;w2<=1004;w2++)
			{
				b[w1][w2]=0;
			}
		}
		b[x][y]=1;
		for (int j = 1;j<=n;j++)
		{
			for (int p = 1;p<=m;p++)
			{
				cin >> a[j][p];
			}
		}
		for (int l = 1;l<=k;l++)
		{
			f(d);
			pd(x,y,d);
		}
		sum=0;
		for (int t1=1;t1<=n;t1++)
		{
			for (int t2=1;t2<=m;t2++)
			{
				//cout << b[t1][t2] <<" ";
				if (b[t1][t2]==1)
				{
					sum++;
				}
			}
			//cout <<endl;
		}
		cout << sum <<endl;
	}
	return 0;
}
