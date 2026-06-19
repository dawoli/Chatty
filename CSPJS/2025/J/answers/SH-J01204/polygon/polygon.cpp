#include <bits/stdc++.h>
using namespace std;
int n;
long long c,w;
int check(int k)
{
	long long s=0;
	w=0;
	while(k>0)
	{
		w++;
		if(k%2==1)
			s++;
		k/=2;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int a[n+5];
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<(1 << n);i++)
	{
		if(check(i)>=3)
		{
			long long sum=0,maxx=0;
			for(int j=1;j<=w;j++)
			{
				long long l=j-1;
				if(i&(1 << l))
				{
					sum+=a[j];
					if(a[j]>maxx)
						maxx=a[j];
				}
			}
			if(sum>2*maxx)
				c++;
			c=c%998244353;
		}
	}
	cout << c;
	return 0;
}
