#include <bits/stdc++.h>
using namespace std;
int t,a[51];
int b[8]={0,0,1,7,4,2,0,8};
int lop(int l,int r,bool bb,int an)
{
	if(l<0)
		return -1;
	int yu=-1;
	while(l>0)
	{
		for(int i=r;i<=7;i++)
		{
			if(i==6&&bb==1)
			{
				if(yu!=-1)
					yu=min(lop(l-6,7,0,6),yu);
				else
					yu=lop(l-6,7,0,6);
			}
			else if(i!=7)
			{
				if(yu!=-1)
					yu=min(lop(l-r,i+1,0,an*10+b[i]),yu);
				else
					yu=lop(l-r,i+1,0,an*10+b[i]);
			}
			else if(l%7==0)
			{
				int k=l/7,v=1,ans=0;
				for(int i=1;i<=k;i++)
				{
					ans+=8*v;
					v*=10;
				}
				yu=min(yu,an*v+ans);
			}
		}
	}
	return yu;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			a[o]=-1;
			continue;
		}
		if(n%7==0)
		{
			a[o]=-1*n;
			continue;
		}
		if(n<7)
		{
			a[o]=b[n];
			if(a[o]==0)
				a[o]=6;
			continue;
		}
		if(n>=8&&n<=9)
		{
			a[o]=10+b[n-2];
			continue;
		}
		if(n>=10&&n<=12)
		{
			a[o]=20+b[n-5];
			continue;
		}
		if(n==13)
		{
			a[o]=68;
			continue;
		}
		if(n>=15&&n<=16)
		{
			a[o]=108+(n-15)*80;
			continue;
		}
		if(n==17)
		{
			a[o]=200;
			continue;
		}
		if(n==18)
		{
			a[o]=208;
			continue;
		}
		if(n==19)
		{
			a[o]=288;
			continue;
		}
		if(n==20)
		{
			a[o]=688;
			continue;
		}
		a[o]=lop(n,2,1,0);
	}
	for(int i=1;i<=t;i++)
	{
		if(a[i]<-1)
		{
			a[i]=abs(a[i]);
			a[i]/=7;
			for(int j=1;j<=a[i];j++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		cout<<a[i]<<endl;
	}
	return 0;
} 
