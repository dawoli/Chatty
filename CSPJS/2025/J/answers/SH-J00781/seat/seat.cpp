#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1],x=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==r)
		{
			x=n*m-i+1;
			break;
		}
	}
	int f=1;
	for(int i=1;i<=m;i++)
	{
		if(f)
		{
			for(int j=1;j<=n;j++)
			{
				x--;
				if(x==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(!f)
		{
			for(int j=n;j>=1;j--)
			{
				x--;
				if(x==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(f)
			f=0;
		else
			f=1;
	}
	return 0;
}
