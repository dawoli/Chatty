#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int pos;
int hang,lie;
bool cmp(int x,int y)
{
	return x > y;
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
	int r = a[1];
	sort(a + 1,a + (n * m) + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == r)
		{
			pos = i;
			break;
		}
	}
	lie = ceil(pos * 1.0 / n);
	if (lie % 2 == 1)
	{
		hang = n - (lie * n - pos);
	}
	else
	{
		hang = (lie * n - pos) + 1;
	}
	cout << lie << ' ' << hang;
	return 0;
}
