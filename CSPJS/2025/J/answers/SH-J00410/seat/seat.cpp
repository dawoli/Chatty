#include <bits/stdc++.h>
using namespace std;
int l[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0;i < n*m;i++)
	{
		scanf("%d",&l[i]);
	}
	int f = l[0];
	int k = -1;
	sort(&l[0],&l[n*m]);
	for (int i = 1;i <= n*m;i++)
	{
		if (f == l[n*m-i])
		{
			k = i;
		}
	}
	int l = (k/n);
	int h = k % n;
	if (h > 0)
	{
		l++;
		if (l % 2 == 0)
		{
			h = m - h + 1;
		}
	}
	else if (h == 0)
	{
		if (l % 2 == 0)
		{
			h = 1;
		}
		else if (l % 2 == 1)
		{
			h = m;
		}
	}
	printf("%d %d",l,h);
	return 0;
 } 
