#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15];
bool cmp(int c,int d)
{
	return c > d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++)
    {
    	cin >> a[i];
	}
	int sb = a[1];
	sort (a + 1,a + n*m + 1,cmp);
	int pos1 = 1,pos2 = 1;
	for (int i = 1;i <= m;i++)
	{
        if (pos1 % 2 == 1)
		{
			for (int j = 1;j <= n;j++)
			{
				b[i][j] = a[pos2];
				pos2++;
			}
		}	
		else
		{
		    for (int j = n;j >= 1;j--)
			{
			    b[i][j] = a[pos2];
				pos2++;	
			}	
		}
		pos1++;	
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (b[i][j] == sb)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
