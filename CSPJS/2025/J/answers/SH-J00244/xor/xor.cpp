#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000005],num=1,x,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	while(num<=n)
	{
		if(x==k)
		{
			num++;
			x=a[num];
			ans++;
			continue;
		}
		num++;
		x=x^a[num];
	}
	cout<<ans;
	return 0;
}
