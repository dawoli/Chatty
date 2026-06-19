#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[100005],s[100005][3005],r[100005],c[100005];
int jl(int ren,int j,int t,int p)
{
	if(r[ren]==j)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==p)
			{
				continue;
			}
			for(int jj=1;jj<=l[i];jj++)
			{
				if(((s[i][jj]!=t)&&(j!=1))||((s[i][jj]!=1)&&(j==1)))
				{
					continue;
				}
				for(int kk=jj+1;kk<=min(l[i],jj+k-1);kk++)
				{
					if(s[i][kk]==c[ren])
					{
						return 1;
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p)
		{
			continue;
		}
		for(int jj=1;jj<=l[i];jj++)
		{
			if(((s[i][jj]!=t)&&(j!=1))||((s[i][jj]!=1)&&(j==1)))
			{
				continue;
			}
			for(int kk=jj+1;kk<=min(l[i],jj+k-1);kk++)
			{
				if(jl(ren,j+1,s[i][kk],i)==1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[i][j]; 
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
		}
		for(int i=1;i<=q;i++)
		{
			cout<<jl(i,1,0,0)<<endl;
		}
	}
	return 0; 
} 
