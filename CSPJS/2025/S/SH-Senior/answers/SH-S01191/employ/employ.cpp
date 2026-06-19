#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long m,k,pc[1000005];
bool ac[1000005];
long long c[1000005];
const long long maxn=1e6;
long long fac[maxn+5];
long long f[(1ll<<18)+5][20][20];
void init()
{
	fac[0]=1;
	for(int i=1;i<=maxn;i++)
	{
		fac[i]=fac[i-1]%mod*i%mod;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	init();
	cin>>k>>m;
	bool sub6=1;
	for(int i=1;i<=k;i++)
	{
		char x;
		cin>>x;
		ac[i]=x-'0';
		if(ac[i]!=1) sub6=0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	if(k<=18)
	{
		f[0][0][0]=1;
		for(int i=0;i<=(1ll<<k)-1;i++)
		{
			for(int j=k-1;j>=0;j--)
			{
				pc[i]+=((i>>j)&1);
			}
		}
		for(int i=0;i<=(1ll<<k)-1;i++)
		{
			for(int j=0;j<=pc[i];j++)
			{
				for(int p=0;p<=k-1;p++)
				{
					for(int u=0;u<=pc[i]-j;u++)
					{
						if((i>>p)&1) continue;
						long long nj=j,nu=u;
						if(ac[pc[i]+1]==0)
						{
							nj=j+1,nu=u;
						}
						else if(ac[pc[i]+1]==1)
						{
							if(j>=c[p+1]) nj=j+1,nu=u;
							else nj=j,nu=u+1;
						}
						bitset<10>bs(i),bs2(i|(1ll<<p));
//						cerr<<bs<<" -> "<<bs2<<": "<<f[i][j][u]%mod<<endl;
						f[i|(1ll<<p)][nj][nu]=(f[i|(1ll<<p)][nj][nu]%mod+f[i][j][u]%mod)%mod;
					}
				}
			}
		}
		long long ans=0;
		for(int j=0;j<=k;j++)
		{
			for(int u=m;u<=k;u++)
			{
				ans=(ans%mod+f[(1ll<<k)-1][j][u]%mod)%mod;
			}
		}
		cout<<ans%mod<<endl;
		return 0; 
	}
	if(sub6)
	{
		cout<<fac[k]%mod<<endl;
		return 0;
	}
	return 0;
}
