#include<iostream>
using namespace std;
#define int long long
bool w[1005][1005]; 
char map[1005][1005];
void c()
{
	for(int i=0;i<1005;i++)
	{
		for(int j=0;j<1005;j++)
		{
			w[i][j] = 0;
			map[i][j] = ' ';
		}
	}
}
int check()
{
	int cnt = 0;
	for(int i=0;i<=1005;i++)
	{
		for(int j=0;j<1005;j++)
		{
			if(w[i][j]==1)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		c;
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		w[x][y] = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> map[i][j];
			}
		}
		for(int i=0;i<k;i++)
		{
			if(d==0)
			{
				if(y+1>=m||map[x][y+1]=='x')
				{
					d = 1;
				}
				else
				{
					y+=1;
				}
			}
			else if(d==1)
			{
				if(x+1>=n||map[x+1][y]=='x')
				{
					d = 2;
				}
				else
				{
					x+=1;
				}
			}
			else if(d==2)
			{
				if(y-1<=0||map[x][y-1]=='x')
				{
					d = 3;
				}
				else
				{
					y-=1;
				}
			}
			else if(d==3)
			{
				if(x-1<=0||map[x-1][y]=='x')
				{
					d = 0;
				}
				else
				{
					x-=1;
				}
			}
			w[x][y] = 1;
		}
		cout << check() << endl;
	}
	return 0;
}
