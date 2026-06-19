#include<bits/stdc++.h>
using namespace std;

const long long Inf=1e17+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

ll n,a[100009];
bool chs[100009];

inline bool add()
{
	for(int i=n;i>=1;i--)
		if(chs[i]==true)
		{
			chs[i]=false;
		}
		else
		{
			chs[i]=true;
			return true;
		}
	return false;
}

inline void solve()
{
	memset(chs,false,sizeof(chs));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll res=-Inf;
	while(add())
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(chs[i]==chs[j])
				{
					if(a[i]==a[j])
						ans+=a[i];
					break;
				}
			}
		}
		res=max(res,ans);
	}
	printf("%lld\n",res);
	return;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}

