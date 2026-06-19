#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,num=0,sy,chi;
	bool flag=1;
	int step,ste;
	int r[100001],m[100001],maxn=0,a[100001],c[100001];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		m[i]=0;
		a[i]=0;
		c[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		m[r[i]]++;
		maxn=max(maxn,r[i]);
	}
	step=1;
	for(int i=1;i<=maxn;i++)
	{
		
		if(m[i]!=0)
		{
			step++;
			a[step]+=m[i];
			c[step]+=m[i];
		}
	}
	num=n;
	sy=n;
	chi=n-a[1];
	for(int i=1;i<=step;i++)
	{
		sy-=a[i];
		if(sy>=a[i]&&chi!=0)
		{
			if(c[i]!=0)
			{
				chi-=c[i];
			} 
			if(chi>=a[i])
			{
				num-=a[i];
				ste=i+1;
				while(a[i]>0)
				{
					if(c[ste]>=a[i])
					{
						c[ste]-=a[i];
						chi-=a[i];
						a[i]=0;
					}
					else if(c[ste]<a[i])
					{
						c[ste]=0;
						chi-=c[ste];
						a[i]-=c[ste];
					}
					if(c[ste]==0)
					{
						ste++;
					}
				}
			}
			else 
			{
				num-=chi;
				chi=0;
				for(int j=i+1;j<=step;j++)
				{
					c[j]=0;
				}
			}
		}
		else if(sy>=a[i]&&chi<a[i])
		{
			if(c[i]!=0)
			{
				chi-=c[i];
			} 
			num-=chi;
			chi=0;
		}
		else if(sy<a[i]&&chi!=0)
		{
			num-=sy;
			chi=0;
			for(int j=i+1;j<=step;j++)
			{
				c[j]=0;
			}
		}
	}
	cout<<num;
	return 0;
} 
