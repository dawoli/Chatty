#include <bits/stdc++.h>
using namespace std;
struct node
{
	int d,s,a;
}b[100005];
int t,n,m,l,v,num,csd[100005],ans,kum,ccsd[3005][3005],cc[3005];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i].s>v && b[i].d<=csd[m])
		{
			ans++;
		}
	}
	cout <<ans <<" " <<m-1 <<endl;
	return;
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i].d<=csd[m] && b[i].s>v)
		{
			ans++;
		}
		else if(b[i].d<csd[m] && b[i].s<=v)
		{
			int f=v*v-b[i].s*b[i].s,g=2*b[i].a;
			if(f%g==0)
			{
				if(b[i].d+f/g<csd[m])
				{
					ans++;
				}
			}
			else
			{
				if(b[i].d*g+f<csd[m]*g)
				{
					ans++;
				}
			}
		}
	}
	cout <<ans <<" " <<m-1 <<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin >>n >>m >>l >>v;
		num=0;
		ans=0;
		kum=0;
		for(int i=1;i<=n;i++)
		{
			cin >>b[i].d >>b[i].s >>b[i].a;
			if(b[i].a==0)
			{
				num++;
			}
			else if(b[i].a>0)
			{
				kum++;
			}
		}
		for(int i=1;i<=m;i++) 
		{
			cin >>csd[i];
		}
		if(num==n)
		{
			solve1();
		}
		else if(kum==n)
		{
			solve2();
		}
	}
	return 0;
}
