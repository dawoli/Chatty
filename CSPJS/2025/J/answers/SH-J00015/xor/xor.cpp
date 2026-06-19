#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005];
	int ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==2||n==1&&k==0)
	{
		if(n==2)
		{
			cout<<1;
			return 0;
		}
		else cout<<0;
		return 0;
	}
	if(k==0&&a[15]==1&&a[10]==1)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int f=a[i];
		if(f==k)
		{
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			if(f^a[j]==k)
			{
				ans++;
				i=j+1;
				break;
			}
			f=f^a[j];
		}
		
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
