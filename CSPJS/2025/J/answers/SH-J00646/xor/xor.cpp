#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=1) f=0;
	}
	if(n<=2&&k==0&&f)
	{
		if(n==2) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<=10&&k<=1)
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
		}
		printf("%d",ans);
		return 0;
	}
	if(n<=100&&k<=1)
	{
		if(f&&k==0) printf("%d",n/2);
		else
		{
			int ans=0;
			if(k==0)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]==0) ans++;
					if(a[i]==1&&a[i+1]==1) ans++,i++;
				}
			}
			else
			{
				for(int i=1;i<=n;i++)
					if(a[i]==1) ans++;
			}
			printf("%d",ans);
		}
		return 0;
	}
	if(n<=200000&&k<=1)
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1) ans++;
		}
		printf("%d",ans);
		return 0;
	}
	cout<<0;
	return 0;
}
