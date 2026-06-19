#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500005],ans,b[500005],l,r;
void check()
{
	for (long long j=1;j<=n;j++)
	{
		long long x=0;
		if (b[j]==1&&j>r)
			continue;
		for (long long i=j;i<=n;i++)
		{
			if (b[i]==0||i<=r)
			{
				x^=a[i];
				if (x==k)
				{
					ans++;
					if (i<=r)
					{
						ans--;
						for (int p=l;p<=r;p++)
							b[p]=0;
					}
					else if(j<=r)
					{
						ans--;
						break;
					}
					for (int p=j;p<=i;p++)
					{
						b[p]=1;
					}
					l=j;
					r=i;
					break;
				}
			}
			else
				break;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==k)
		{
			b[i]=1;
			ans++;
		}
	}
	int flag=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=1)
			flag=1;
	}
	if (k==0&&flag==0)
	{
		cout<<n/2;
		return 0;
	}
	check();
	cout<<ans;
	return 0;
}
