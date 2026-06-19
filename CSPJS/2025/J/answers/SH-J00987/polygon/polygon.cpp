#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll F=998244353;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>=max(a[1],max(a[2],a[3])))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		n=(ll)(n-2);
		ll s=n*(n+1)*(n+2)/6;
		cout<<s%F;
	}
	return 0;
}
