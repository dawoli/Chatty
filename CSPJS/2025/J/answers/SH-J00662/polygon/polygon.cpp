#include<bits/stdc++.h>
using namespace std;

int n,a[5005],flag;
long long ans,maxn,num;
void check1(int x,int y)
{
	if (y==0)
	{
		if (maxn*2<num)
		{
			ans=(ans+1)%998244353;
		}
	}
	else
	{
		for (int i=x;i<=n-y+1;i++)
		{
			if (y==1)
				maxn=a[i];
			num+=a[i];
			check1(i+1,y-1);
			num-=a[i];
		}
	}
}
void check()
{
	for (int i=3;i<=n;i++)
	{
		check1(1,i);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1)
			flag=1;
	}
	if(flag==0)
	{
		for (int i=3;i<=n;i++)
		{
			long long ans1=1;
			for (int j=n;j>n-i;j--)
			{
				ans1*=j%=998244353;
			}
			for(int j=1;j<=i;j++)
			{
				ans1/=j%=998244353;
			}
			ans+=ans1%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	sort(a+1,a+1+n);
	if (n==3)
	{
		if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	check();
	cout<<ans%998244353;
	return 0;
}
