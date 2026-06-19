#include<cstdio>
#include<cstring>
using namespace std;
const long long Inf=1e9+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

ll n,k,q,l[100009],s[2009][2009];
bool can[100009];

inline void solve()
{
	memset(can,false,sizeof(can));
	scanf("%lld %lld %lld",&n,&k,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&l[i]);
		ll dis=-1;
		for(int j=1;j<=l[i];j++)
		{
			scanf("%lld",&s[i][j]);
			if(s[i][j]==1)
			{
				if(dis!=-1&&dis<k&&dis>=1)
					can[s[i][j]]=true;
				dis=0;
			}
			else
			{
				if(dis!=-1&&dis<k&&dis>=1)
					can[s[i][j]]=true;
			}
			if(dis!=-1)
				dis++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ll r,c;
		scanf("%lld %lld",&r,&c);
		if(r==1)
		{
			if(can[c]==true)
				printf("1\n");
			else printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return;
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}

