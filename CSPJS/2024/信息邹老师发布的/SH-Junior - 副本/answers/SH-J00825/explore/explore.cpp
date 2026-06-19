#include <bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,p;
bool b[1005][1005];
string a[1005];
void f(int m1,int n1)
{
	if (m1 > 0 && n1 >= 0 && m1 <= n && n1 < m && a[m1][n1] == '.')
	{
		if (!b[m1][n1])
		{
			b[m1][n1] = true;
			p++;
		}
		x = m1;
		y = n1;
	}
	else
		d = (d + 1) % 4;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		p = 1;
		memset(b,0,sizeof(b));
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		y--;b[x][y] = true;
		for (int j = 1;j <= n;j++)
			cin >> a[j];
		for (int j = 1;j <= k;j++)
			if (d == 0)
				f(x,y + 1);
			else if (d == 1)
				f(x + 1,y);
			else if (d == 2)
				f(x,y - 1);
			else
				f(x - 1,y);
		cout << p << endl;
	}
	return 0;
}
