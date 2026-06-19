#include<bits/stdc++.h>
using namespace std;
int a[10000],n,b[10000];
long long ans;
const int mod=998244353;
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
    	b[i]=a[i]+b[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int c=3;c<=n;c++)
			{
				if(b[c]-(2*a[c])-b[j+i]+b[i]>0)
				{
					ans++;
				}
			}
	    }
	}
	cout<<ans%mod;
	return 0;
}
