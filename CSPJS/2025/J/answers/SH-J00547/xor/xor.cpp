#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++)
	{
		int test=0;
		for(int j=i;j<=n;j++)
		{
			test=test^a[j];
			if(test==k)
			{
				ans++;
				i=j;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
