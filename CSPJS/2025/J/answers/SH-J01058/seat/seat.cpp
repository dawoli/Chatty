#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],q,c=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	for	(int i=1;i<=n;i++)
	{
		if (i%2==1)
			for (int j=1;j<=m;j++)
			{
				if (a[c]==q)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		else
		{
			for (int j=m;j>=1;j--)
			{
				if (a[c]==q)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		}
	}
}
