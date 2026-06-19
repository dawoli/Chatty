#include <bits/stdc++.h>
using namespace std;
long long n,sum,s,a[5005],b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int l=1;l<=n-2;l++)
	{
		for(int r=l+2;r<=n;r++)
		{
			sum=b[r]-b[l-1];
			if(sum>2*r)
			{
				for(int i=l;i<=r;i++)
				{
					cout<<a[i]<<" ";
				}
				s++;
				cout<<endl;
			}
		}
	}
	cout<<s%998244353;
	return 0;
}
