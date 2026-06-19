#include <bits/stdc++.h>
using namespace std;

long long n,m,a[105],x,r,c=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for (int i=n*m;i>=1;i--)
	{
		if (c%2==1)
			r++;
		else
			r--;
		if (r>n)
		{
			r=n;
			c++;
		}
		if(r<1)
		{
			r=1;
			c++;
		}
		if (a[i]==x)
		{
			cout<<c<<" "<<r;
			return 0;
		}
	}
}
