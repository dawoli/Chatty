#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int x;
	int y;
	int z;
	int ma;
	int mb;
	int mc;
	int cho;
} c[100005];

int t, n;
int y, e, s;
int ans;

bool cmp(Node x, Node y)
{
	return (x.ma > y.ma) || (x.ma == y.ma && x.mb > y.mb) || (x.ma == y.ma && x.mb == y.mb && x.mc > y.mc);
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

int suan()
{
	int maxn = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i].cho == 1) maxn += c[i].x;
		else if(c[i].cho == 2) maxn += c[i].y;
		else maxn += c[i].z;
	}
//	cout << maxn << endl;
	return maxn;
}

void dfs(int v, int a1, int b1, int c1)
{
	if(a1 <= n/2 && b1 <= n/2 && c1 <= n/2)
	{
		ans = max(suan(), ans);
//		cout << a1 << " " << b1 << " " << c1 << endl;
		return;
	}
	if(v == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(c[i].cho == 1)
			{
				if(c[i].y > c[i].z)
				{
					c[i].cho = 2;
					dfs(v, a1-1, b1+1, c1);
					c[i].cho = 1;
				}
				else
				{
					c[i].cho = 3;
					dfs(v, a1-1, b1, c1+1);
					c[i].cho = 1;
				}
			}
		}
	}
	else if(v == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			if(c[i].cho == 2)
			{
				if(c[i].x > c[i].z)
				{
					c[i].cho = 1;
					dfs(v, a1+1, b1-1, c1);
					c[i].cho = 2;
				}
				else
				{
					c[i].cho = 3;
					dfs(v, a1, b1-1, c1+1);
					c[i].cho = 2;
				}
			}
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			if(c[i].cho == 3)
			{
				if(c[i].y > c[i].z)
				{
					c[i].cho = 1;
					dfs(v, a1+1, b1, c1-1);
					c[i].cho = 3;
				}
				else
				{
					c[i].cho = 2;
					dfs(v, a1, b1+1, c1-1);
					c[i].cho = 3;
				}
			}
		}
	}
	return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		y = 0, e = 0, s = 0;
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> c[i].x;
			cin >> c[i].y;
			cin >> c[i].z;
			c[i].ma = max(max(c[i].x, c[i].y), c[i].z);
			c[i].mc = min(min(c[i].x, c[i].y), c[i].z);
			if(c[i].x == c[i].ma) c[i].mb = max(c[i].y, c[i].z);
			else if(c[i].y == c[i].ma) c[i].mb = max(c[i].x, c[i].z);
			else c[i].mb = max(c[i].x, c[i].y);
		}
		sort(c+1, c+n+1, cmp);
		for(int i = 1; i <= n; i++)
		{
			if(c[i].x == c[i].ma)
			{
				y++;
				c[i].cho = 1;
			}
			else if(c[i].y == c[i].ma)
			{
				e++;
				c[i].cho = 2;
			}
			else
			{
				s++;
				c[i].cho = 3;
			}
		}
		if(y >= e && e >= s) dfs(1, y, e, s);
		else if(e >= y && y >= s) dfs(2, y, e, s);
		else dfs(3, y, e, s);
		cout << ans << endl;
	}
	return 0;
}
