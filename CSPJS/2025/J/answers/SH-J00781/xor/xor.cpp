#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			x=0;
			break;
		}
	}
	if(x)
	{
		cout<<n/2;
		return 0;
	}
	else
	{
		int b=0,c=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				b++;
			else
				c++;
		}
		if(k)
		{
			cout<<b;
			return 0;
		}
		else
		{
			cout<<c+b/2;
			return 0;
		}
	}
	return 0;
}
