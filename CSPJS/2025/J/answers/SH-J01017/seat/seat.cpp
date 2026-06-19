#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005],b[100005],c,d,n,m,mx,l,x,r,h;
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> b[i];
	}
	c = b[1];
	for (int i = 1; i <= n*m; i++)
	{
		for (int j = 1; j <= n*m; j++)
		{
			if(b[i] > b[j])
			{
				x = b[j];
				b[j] = b[i];
				b[i] = x;
			}
		}
	}
	for (int i = 1; i <= n*m; i++)
	{
		if(b[i] == c)
		{
			l = i;
		}
	}
	r = l % n;
	h = l / n;
	if(r == 0)
	{
		if(h % 2 == 0)
		{
			cout << h << " " << "1";
		}
		else
		{
			cout << h << " " << n;
		}
	}
	else
	{
		if((h+1) % 2 == 0)
		{
			cout << h+1 << " " << n-r+1;
		}
		else
		{
			cout << h+1 << " " << r;
		}
	}
	return 0;
}
