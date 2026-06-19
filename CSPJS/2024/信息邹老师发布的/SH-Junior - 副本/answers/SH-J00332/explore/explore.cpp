#include<bits/stdc++.h>
#include <string>
using namespace std;
int ans[8];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i = 1; i <= t; i ++)
	{
		int n,m,k;
		int x,y,d;
		int cnt = 1;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		char a[1005][1005];
		x --;
		y --;
		for(int j = 0; j < n; j ++)
			for(int l = 0; l < m; l ++) cin >> a[j][l];
		a[x][y] ++;
		while(k > 0)
		{
			if(d == 0)
			{
				if(a[x][y+1] != 120 && (y + 1 < m)) 
				{
					y ++;
					if(a[x][y] == 46) 
					{
						cnt ++;
						a[x][y] ++;
					}
				}
				else d = (d+1) % 4;
			}
			else if(d == 1)
			{
				if(a[x+1][y] != 120 && (x + 1 < n)) 
				{
					x ++;
					if(a[x][y] == 46) 
					{
						cnt ++;
						a[x][y] ++;
					}
				}
				else d = (d+1) % 4;
			}
			else if(d == 2)
			{
				if(a[x][y-1] != 120 && (y - 1 >= 0)) 
				{
					y --;
					if(a[x][y] == 46) 
					{
						cnt ++;
						a[x][y] ++;
					}
				}
				else d = (d+1) % 4;
			}
			else if(d == 3)
			{
				if(a[x-1][y] != 120 && (x - 1 >= 0)) 
				{
					x --;
					if(a[x][y] == 46) 
					{
						cnt ++;
						a[x][y] ++;
					}
				}
				else d = (d+1) % 4;
			}
			k --;
		}
		ans[i] = cnt;
	}
	for(int i = 1; i <= t; i ++)
		printf("%d\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
