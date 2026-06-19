#include<bits/stdc++.h>
using namespace std;
int n,k;
int s[500005],f[500005],g[500005][300];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) 
	{
		int x;cin>>x;
		s[i]=s[i-1]^x;
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;++i)
		{
			f[i]=f[i-1];
			for(int j=0;j<i;++j)
				if((s[i]^s[j])==k)
					f[i]=max(f[i],f[j]+1);
		}
		cout<<f[n];
	}
	else
	{
		for(int i=0;i<256;++i)
		{
		int tmp=n+1;
		for(int j=n+1;j>=0;--j)
		{
			if(s[j]==i) tmp=j;
			g[j][i]=tmp;
		}
		}
		int pos,ans=0,cnt=0;
		for(int i=0;i<=n;i=pos)
		{
			pos=n+1;
			for(int j=0;j<256;++j)
			{
				int tmp=g[i][j];
				if(g[tmp][j^k]>tmp) pos=min(pos,g[tmp][j^k]);
			}
			if(pos<=n) ans++;
		}
		cout<<ans;
	}
	return 0;
}	
