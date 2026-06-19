#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,k,q,len[1005],s[1005][2005],lastp,lastlastp,r,c;
bool f[200005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		scanf("%lld%lld%lld",&n,&k,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&len[i]);
			for(int j=1;j<=len[i];j++) scanf("%lld",&s[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			lastp=-1e9;
			lastlastp=-1e9;
			for(int j=1;j<=len[i];j++)
			{
				if(s[i][j]==1) lastp=j;
				if(j>lastlastp+k-1)
				{
					lastlastp=lastp;
					lastp=-1e9;
				}
				if(j<=lastlastp+k-1&&j>lastlastp) f[s[i][j]]=1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			scanf("%lld%lld",&r,&c);
			cout<<f[c]<<endl;
		}
	}
} 
