#include <bits/stdc++.h>
using namespace std;

int n,a[5005],ma=-1,y=998244353;
long long x=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>ma)
			ma=a[i];
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(n==4)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			x++;
		if(a[1]+a[2]>a[4])
			x++;
		if(a[1]+a[3]>a[4])
			x++;
		if(a[2]+a[3]>a[4])
			x++;
		if(a[1]+a[2]+a[3]>a[4])
			x++;
		cout<<x;
		return 0;
	}
	if(n==5)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			x++;
		if(a[1]+a[2]>a[4])
			x++;
		if(a[1]+a[2]>a[5])
			x++;
		if(a[1]+a[3]>a[4])
			x++;
		if(a[1]+a[3]>a[5])
			x++;
		if(a[1]+a[4]>a[5])
			x++;
		if(a[2]+a[3]>a[4])
			x++;
		if(a[2]+a[3]>a[5])
			x++;
		if(a[2]+a[4]>a[5])
			x++;
		if(a[3]+a[4]>a[5])
			x++;
		if(a[1]+a[2]+a[3]>a[4])
			x++;
		if(a[1]+a[2]+a[3]>a[5])
			x++;
		if(a[1]+a[2]+a[4]>a[5])
			x++;
		if(a[1]+a[3]+a[4]>a[5])
			x++;
		if(a[2]+a[3]+a[4]>a[5])
			x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])
			x++;
		cout<<x;
		return 0;
	}
	if(n==6)
	{
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			x++;
		if(a[1]+a[2]>a[4])
			x++;
		if(a[1]+a[2]>a[5])
			x++;
		if(a[1]+a[2]>a[6])
			x++;
		if(a[1]+a[3]>a[4])
			x++;
		if(a[1]+a[3]>a[5])
			x++;
		if(a[1]+a[3]>a[6])
			x++;
		if(a[1]+a[4]>a[5])
			x++;
		if(a[1]+a[4]>a[6])
			x++;
		if(a[1]+a[5]>a[6])
			x++;
		if(a[2]+a[3]>a[4])
			x++;
		if(a[2]+a[3]>a[5])
			x++;
		if(a[2]+a[3]>a[6])
			x++;
		if(a[2]+a[4]>a[5])
			x++;
		if(a[2]+a[4]>a[6])
			x++;
		if(a[2]+a[5]>a[6])
			x++;
		if(a[3]+a[4]>a[5])
			x++;
		if(a[3]+a[4]>a[6])
			x++;
		if(a[3]+a[5]>a[6])
			x++;
		if(a[4]+a[5]>a[6])
			x++;
		if(a[1]+a[2]+a[3]>a[4])
			x++;
		if(a[1]+a[2]+a[3]>a[5])
			x++;
		if(a[1]+a[2]+a[3]>a[6])
			x++;
		if(a[1]+a[2]+a[4]>a[5])
			x++;
		if(a[1]+a[2]+a[4]>a[6])
			x++;
		if(a[1]+a[2]+a[5]>a[6])
			x++;
		if(a[1]+a[3]+a[4]>a[5])
			x++;
		if(a[1]+a[3]+a[4]>a[6])
			x++;
		if(a[1]+a[3]+a[5]>a[6])
			x++;
		if(a[1]+a[4]+a[5]>a[6])
			x++;
		if(a[2]+a[3]+a[4]>a[5])
			x++;
		if(a[2]+a[3]+a[4]>a[6])
			x++;
		if(a[2]+a[3]+a[5]>a[6])
			x++;
		if(a[2]+a[4]+a[5]>a[6])
			x++;
		if(a[3]+a[4]+a[5]>a[6])
			x++;
		if(a[1]+a[2]+a[3]+a[4]>a[5])
			x++;
		if(a[1]+a[2]+a[3]+a[4]>a[6])
			x++;
		if(a[1]+a[2]+a[3]+a[5]>a[6])
			x++;
		if(a[1]+a[2]+a[4]+a[5]>a[6])
			x++;
		if(a[1]+a[3]+a[4]+a[5]>a[6])
			x++;
		if(a[2]+a[3]+a[4]+a[5]>a[6])
			x++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])
			x++;
		cout<<x;
		return 0;
	}
	if(ma==1)
	{
		for(int i=3;i<=n;i++)
		{
			int b=min(i,n-i);
			if(b==0)
				x++;
			else
			{
				long long s1=1,s2=1;
				for(int j=n;j>n-b;j--)
					s1*=j;
				for(int j=1;j<=b;j++)
					s2*=j;
				long long s=s1/s2;
				x+=s;
				x%=y;
			}
		}
		cout<<x;
		return 0;
	}
	return 0;
}
