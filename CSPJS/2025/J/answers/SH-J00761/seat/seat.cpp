#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1],b;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==t) b=i;
	}
	int x=0,y=1,op=0;
	for (int i=1;i<=b;i++)
	{
		if (op)
		{
			x--;
			if (x==0)
			{
				x=1;
				y++;
				op=0;
			}
		}
		else
		{
			x++;
			if (x==n+1)
			{
				x=n;
				y++;
				op=1;
			}
		}
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}
