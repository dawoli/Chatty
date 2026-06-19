#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t;
    cin >> t;
    string loc;
    for(int i = 1;i<=t;i++)
    {
    	int n,m,k,x,y,d,cnt = 1;
    	char o[1001];
    	cin >> n >> m >> k;
    	cin >> x >> y >> d;
    	for(int j = 1;j<=n;j++)
    	{
    		cin >> o;
    		for(int q = 1;q<=m;q++)
    		{
    			if(o[q] == 'x')
    			{
    				a[n][m] = 1;
				}
			}
		}
		for(int p = 1;p<=k;p++)
		{
			int x1 = x,y1 = y;
			if(d == 0)
			{
				y1++;
			}
			if(d == 1)
			{
				x1++;
			}
			if(d == 2)
			{
				y1--;
			}
			if(d == 3)
			{
				x1--;
			}
			if(a[x1][y1] !=1  && x1 > 0 && x1 <= n &&  y1 > 0 && y1 <= m)
			{
				if(a[x][y] == 2)
				{
					cnt--;
				}
				a[x][y] = 2;
				x = x1;
				y = y1;
				cnt++;
			}
			else
			{
				d++;
				if(d>=4)
				{
					d = d%4;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
