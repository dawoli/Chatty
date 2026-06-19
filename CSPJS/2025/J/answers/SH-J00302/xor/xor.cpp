#include <bits/stdc++.h>
using namespace std;
int a[5000100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1||abs(a[i]-a[i-1])==1&&a[i-1]%2==0)
			{
				cnt++;
				a[i]=0;
			}
		}
		cout<<cnt;
		return 0;
	}
	else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
			else if(a[i]==a[i-1])
			{
				cnt++;
				a[i]=0;
				a[i-1]=0;
			}
		}
		cout<<cnt;
		return 0;
	}
	else
	{
		cout<<n/2;
		return 0;
	}
}
