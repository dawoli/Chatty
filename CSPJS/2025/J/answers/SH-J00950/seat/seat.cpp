#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1)
		{
			s=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==s)
		{
			p=i;
		}
	}
	int c,r;
	if (p%n==0)
	{
		c=p/n;
	}
	else
	{
		c=p/n+1;
	}
	if (c%2==1)
	{
		r=p%n;
		if (r==0)
		{
			r=n;
		}
	}
	else
	{
		if (p%n!=0)
		{
			r=n-p%n+1;
		}
		else
		{
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
