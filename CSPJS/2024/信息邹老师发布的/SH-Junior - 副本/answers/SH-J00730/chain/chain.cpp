#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool f[1005][2005][15];
struct line
{
	int L;
	int l[2005];
}a[1005];

struct task
{
	int r,c;
}t[1005];
int N,K,Q,maxr;

bool check(int u,int b,int c) 
{
	for(int i=b-min(K-1,b-1);i<b;i++)
	{
		if(a[u].l[i]==c)
		{
			return true;
		}
	}
	return false;
}
bool ct(int x,int y,int z)
{
	for(int i=1;i<=N;i++)
	{
		if(i==x)	continue;
		for(int j=1;j<=a[i].L;j++)
		{
			if(check(x,y,a[i].l[j])&&f[i][j][z-1]==true)
				return true;
				
		}	
	}
	return false;
 } 
void init()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<a[i].L;j++)
		{
			if(a[i].l[j]==1)
			{
				for(int jj=j+1;jj<=min(j+K-1,a[i].L);jj++)
				{
					f[i][jj][1]=true;
				}
			}
		}
	}
	for(int k=2;k<=maxr;k++)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=2;j<=a[i].L;j++)
			{
				if(ct(i,j,k))
					f[i][j][k]=true;
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int g=1;g<=T;g++)
	{
		scanf("%d%d%d",&N,&K,&Q);
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&a[i].L);
			for(int j=1;j<=a[i].L;j++)
				scanf("%d",&a[i].l[j]);
		}
		maxr=-1;
		for(int i=1;i<=Q;i++)
		{
			scanf("%d%d",&t[i].r,&t[i].c);
			maxr=max(maxr,t[i].r);
		}
		
		init();
		
		for(int s=1;s<=Q;s++)
		{
			bool tmp=false;
			for(int i=1;i<=N;i++)
			{
				for(int j=2;j<=a[i].L;j++)
				{
					if(a[i].l[j]==t[s].c&&f[i][j][t[s].r]==true)
					{
						tmp=true;
						break;
					}
				}
				if(tmp)	break;
			}
			if(tmp)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	
	return 0;
}

