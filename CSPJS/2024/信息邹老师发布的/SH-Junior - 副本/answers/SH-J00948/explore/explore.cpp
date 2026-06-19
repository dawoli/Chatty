#include<bits/stdc++.h>
using namespace std;
long long a,n,m,k,x,y,z,g=1;
int h[5005][5005];
char b[5005][5005];
void A(long long c,long long d,long long e,long long f)
{
	if(c==0)
	{
		return ;
	}
	if(f==1)
	{
		if(n==d)
		{
			A(c-1,d,e,(f+1)%4);
		}
		else
		{
			if(b[d+1][e]=='.')
			{
				if(h[d+1][e]==0)
				{
					g++;
				}
				h[d][e]=1;
				A(c-1,d+1,e,f);
			}
			else
			{
				A(c-1,d,e,(f+1)%4);
			}
		}
	}
	else if(f==0)
	{
		if(m==e)
		{
			A(c-1,d,e,(f+1)%4);
		}
		else
		{
			if(b[d][e+1]=='.')
			{
				if(h[d][e+1]==0)
				{
					g++;
				}
				h[d][e]=1;
				A(c-1,d,e+1,f);
			}
			else
			{
				A(c-1,d,e,(f+1)%4);
			}
		}
	}
	else if(f==2)
	{
		if(1==e)
		{
			A(c-1,d,e,(f+1)%4);
		}
		else
		{
			if(b[d][e-1]=='.')
			{
				if(h[d][e-1]==0)
				{
					g++;
				}
				h[d][e]=1;
				A(c-1,d,e-1,f);
			}
			else
			{
				A(c-1,d,e,(f+1)%4);
			}
		}
	}
	else if(f==3)
	{
		if(1==d)
		{
			A(c-1,d,e,(f+1)%4);
		}
		else
		{
			if(b[d-1][e]=='.')
			{
				if(h[d-1][e]==0)
				{
					g++;
				}
				h[d][e]=1;
				A(c-1,d-1,e,f);
			}
			else
			{
				A(c-1,d,e,(f+1)%4);
			}
		}
	}
	return ;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>n>>m>>k>>x>>y>>z;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cin>>b[j][k];
			}
		}
		g=1;
		A(k,x,y,z);
		cout<<g<<endl;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				h[j][k]=0;
			}
		}
	}
	return 0;
}
