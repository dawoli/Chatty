#include <bits/stdc++.h>
using namespace std;
int n,m;
bool flag = true;
int a[20][20] = {};
int cj[200] = {};
int R = 0;
int x = 1,y = 1;
int k = 0;//排名（用于决定座位号） 
bool comp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int all = n*m;
	cin>>R;
	cj[1] = R;
	for (int p = 2;p<=all;p++)
	{
		cin>>cj[p];
	}
	while (x<=m)
	{
		k++;
		a[x][y] = k;
		if (flag == true)
		{
			y++;
			if (y == n+1)
			{
				flag = !flag;
				x++;
			}
		}
		if (flag == false)
		{
			if (y == 1)
			{
				flag = !flag;
				x++;
			}
			else
			{
				y--;
			}
		}
	}
	sort(cj+1,cj+all+1,comp);
	for (int i=1;i<=all;i++)
	{
		if (R == cj[i])
		{
			R = i;//R的作用从存储小R的成绩变为存储小R的排名 
			break;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j] == R)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
