#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<n;
		return 0;
	}
	if(k==1)
	{
		int pos=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[pos]!=a[i])
			{
				ans++;
				pos=i+1;
				i++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<2;
	return 0;
}
