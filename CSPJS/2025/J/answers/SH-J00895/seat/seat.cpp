#include<bits/stdc++.h>
using namespace std;
int x,y,a[105],flag,flag1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	int n=x*y;
	for(int i=0;i<n;i++)cin>>a[i];
	int b=a[0],c;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]==b)
		{
			c=i;
			break;
		}
	}
	c++;
	if(c%y==0)
	{
		if((c/y)%2==0)cout<<c/y+1<<' '<<1;
		else cout<<c/y+1<<' '<<2;
		return 0;
	}
	else
	{
		flag=c/y+1;
		if(flag%2==0)
		{
			c=0;
			for(int i=1;i<x;i++)
			{
				if(a[(flag-1)*x+i]==b)
				{
					c=i;
					break;
				}
			}
			cout<<x-c<<' '<<flag; 
			return 0;
		}
		else
		{
			c=0;
			for(int i=1;i<x;i++)
			{
				if(a[(flag)*x+i]==b)
				{
					c=i;
					break;
				}
			}
			cout<<flag<<' '<<c; 
			return 0;
		}
	}
	return 0;
}
