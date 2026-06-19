#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
typedef long long ll;

ll n,a[100009],ans=0;
ll yh[5009][5009];
vector<ll> vec[2]; 

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n<=20)
	{
		vec[0].clear();
		vec[1].clear();
		vec[1].push_back(0LL);
		for(int i=1;i<=n;i++)
		{
			vec[((i&1)+1)%2].clear();
			for(auto j:vec[i&1])
				vec[((i&1)+1)%2].push_back(j+a[i]);
			sort(vec[((i&1)+1)%2].begin(),vec[((i&1)+1)%2].end());
//			printf("%lld\n",vec[((i&1)+1)%2][vec[((i&1)+1)%2].size()-1]);
			ll pos=upper_bound(vec[((i&1)+1)%2].begin(),vec[((i&1)+1)%2].end(),2*a[i])-vec[((i&1)+1)%2].begin();
			pos=(ll)vec[((i&1)+1)%2].size()-pos;
			if(i>=3) ans+=pos, ans%=Mod;
//			printf("%lld %lld\n",ans,pos);
			for(auto j:vec[i&1])
				vec[((i&1)+1)%2].push_back(j); 
		}
		printf("%lld\n",ans);
	}
	else
	{
		yh[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=i;j++)
			{
				if(j!=0)
					yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
				else yh[i][j]=yh[i-1][j];
			}
		for(int i=3;i<=n;i++)
		{
			ans+=yh[n][i];
			ans%=Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
