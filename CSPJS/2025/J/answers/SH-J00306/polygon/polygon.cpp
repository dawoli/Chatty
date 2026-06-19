#include<bits/stdc++.h>
using namespace std;

int n,a[5005],kk=1,res;
int sum(int x,int y)
{
	int ans=0;
	for(int i=x;i<=y;i++)
	{
		ans+=a[i];
	}
	return ans;
}
int MAX(int x,int y)
{
	int ans=0;
	for(int i=x;i<=y;i++)
	{
		ans=max(ans,a[i]);
	}
	return ans;
}
int C(int x,int y)
{
	int x1=1,y1=1;
	for(int i=x;i>=x-y+1;i--)
	{
		x1=x1*i;
	}
	for(int i=y;i>=1;i--)
	{
		y1=y1*i;
	}
	return x1/y1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)kk=0;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(sum(1,3)>MAX(1,3)*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(kk==1)
	{
		for(int i=3;i<=n;i++)
		{
			res+=C(n,i);
		}
		cout<<res%998;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=n-i+1;l>=1;l--)
		{
			if(l==-1)continue;
			int r=l+i;
			if(sum(l,r)>MAX(l,r)*2)
			{
				for(int i=3;i<=n;i++)
				{
					res+=C(n,i);
				}
				for(int j=l;j<=r;j++)
				{
					a[j]=-1;
				}
			}
		}
	}
	cout<<res%998;
}
