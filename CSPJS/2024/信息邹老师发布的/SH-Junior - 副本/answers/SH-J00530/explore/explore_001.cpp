#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int b[1000010];
int main()
{
	freopen("explore","in",stdin);
	freopen("explore","out",stdout);
	int t;
	cin >> t;
	int cnt = 1;
	for(int f = 1; f<=t ;f++)
	{
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for(int i = 1; i<= n; i++)
		{
			for(int j= 1 ; j <= m; j++)
			{
				cin >>a[i][j];
			}
		}
		while(k>=1)
		{
			if(d==0)
			{
				if(y+1<=m&&a[x][y+1]=='.')
				{
					a[x][y]=a[x][y+1];
					cnt+=1;
				}
				else if(a[x+1][y]=='x')
				{
					b[f]=cnt;
					break;
				}
				else
				{
					d=(d+1)%4;
				}
				k-=1;
			}
			if(d==1)
			{
				if(x+1<=n&&a[x+1][y]=='.')
				{
					a[x][y]=a[x+1][y];
					cnt+=1;
				}
				else if(a[x+1][y]=='x')
				{
					b[f]=cnt;
					break;
				}
				else
				{
					d=(d+1)%4;
				}
				k-=1;
			}
			if(d==2)
			{
				if(y-1>=1&&a[x][y-1]=='.')
				{
					a[x][y]=a[x][y-1];
					cnt+=1;
				}
				else if(a[x+1][y]=='x')
				{
					b[f]=cnt;
					break;
				}
				else
				{
					d=(d+1)%4;
				}
				k-=1;
			}
			if(d==3)
			{
				if(x-1>=1&&a[x-1][y]=='.')
				{
					a[x][y]=a[x-1][y];
					cnt+=1;
				}
				else if(a[x+1][y]=='x')
				{
					b[f]=cnt;
					break;
				}
				else
				{
					d=(d+1)%4;
				}
				k-=1;
			}
		}
		b[f]=cnt;
	}
	for(int i =1; i <=t; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
