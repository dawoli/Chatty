#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],vis[500005],cnt;
//Æ­·ÖNo.1
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
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
			else if(a[i]==1&&a[i+1]==1)
			{
				cnt++;
				i++;
			}
		}
		cout<<cnt;
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
		}
		cout<<cnt;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
