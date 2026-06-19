#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m,c,r,b,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++)
	{
		if (a[n*m-i+1]==b)
		{
			d=i;
			break;
		}
	}
	c=d/n;
	r=d%n;
	if (r!=0) c++;
	else r=n;
	if (c%2==0) r=(n+1)-r;
	cout << c << ' ' << r;
	return 0;
}
