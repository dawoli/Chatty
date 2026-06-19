#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long ans=a[1];
	sort(a+1,a+n*m+1);
	long long rnk=1;
	for (long long i=n*m;i>0;i--)
	{
		if (a[i]==ans)
		{
			break;
		}
		rnk++;
	}
	long long r;
	long long c=rnk/n;
	if (rnk%n!=0)
	{
		c++;
	}
	if (c%2==0)
	{
		if (rnk%n==0)
		{
			r=1;
		}
		else
		{
			r=n-rnk%n+1;
		}
	}
	else
	{
		if (rnk%n==0)
		{
			r=n;
		}
		else
		{
			r=rnk%n;
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
