#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005],p[100005];

int con(int x,int n)
{
	int r = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == x)
		{
			r++;
		}
	}
	return r;
}

int con1(int x,int n)
{
	int r = 0;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] >= x)
		{
			r++;
		}
	}
	return r;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		for(int j = 1; j <= 200000; j++)
		{
			a[j] = 0;
			b[j] = 0;
			c[j] = 0;
		}
		int n,m,l,v;
		cin >> n >> m >> l >> v;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[j] >> b[j] >> c[j];
		}
		for(int j = 1; j <= m; j++)
		{
			cin >> p[j];
		}
		if(con(0,n) == n)
		{
			cout << con1(v,n) << m - 1;
		}
	}
	return 0;
}
// 00401562 006c6000
