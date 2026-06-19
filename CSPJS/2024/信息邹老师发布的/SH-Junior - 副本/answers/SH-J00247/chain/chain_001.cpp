#include<bits/stdc++.h>
using namespace std;
int t;
int a[10001][10001];
int r[100001],c[100001];
int nump[100001];
bool f(int x,int y,int limit,int finde,int turn,int one,int n,int len)
{
	/*if(turn) 
	for(int i=2;i<=k;i++)
	{
		for(int k=star;k<j+i;k++)
		{
			if(turn==0&&a[now][k]!=1)
			continue;
			if(a[now][k]==end&&turn==r[now])
			{
				return true;
			}
			return f()	
		}
	}*/
	if(turn>=limit)
	return false;
	for(int i=2;i<=one;i++)
	{
		for(int k=y;k<y+i&&y+i<=n;k++)
		{
			if(a[x][k]==finde&&turn==limit)
			{
				return true;
			}
			bool flag=0;
			for(int j=0;j<n;j++)
			{
				if(j==x) continue;
				for(int w=0;w<len;w++)
				{
					if(a[j][w]==a[x][k])
					{
						if(f(j,w,limit,finde,turn,one,n,len)==1)
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++)
	{
		int n,o,q;
		cin>>n>>o>>q;
		for(int i=0;i<n;i++)
		{
			int len;
			cin>>len;
			nump[i]=len;
			for(int j=0;j<len;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int k=0;k<q;k++)
		{
			cin>>r[k]>>c[k];
			bool flag2=0;
			for(int i=0;i<n;i++)
			{
				bool flag=0;
				for(int j=0;j<nump[i];j++)
				{
					if(a[i][j]==1)
					{
						if(f(i,j,r[k],c[k],0,o,n,nump[i])==1)
						{
							flag=1;
							break;
						}
						
					}
				}
				if(flag==1) 
				{
					flag2=1;
					break;
				}
			}
			if(flag2==1)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
