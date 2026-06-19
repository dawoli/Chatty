#include<bits/stdc++.h>
using namespace std;

const long long Inf=1e17+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

ll n,ans=0,r[100009],cnt[100009];
vector<pair<ll,ll> > vec,kgj;

inline bool cmp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
	return a.first<b.first;
}

inline void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
		cnt[r[i]]++; 
	}
	for(int i=1;i<=1e5;i++)
		if(cnt[i]!=0)
		{
			vec.push_back({i,cnt[i]});
			kgj.push_back({i,cnt[i]});
		}
	sort(vec.begin(),vec.end(),cmp);
	sort(kgj.begin(),kgj.end(),cmp);
	for(int i=0;i<vec.size();i++)
	{
		int dq=vec[i].first;
		for(int j=i+1;j<vec.size()&&vec[i].second>0;)
		{
			if(kgj[j].second==0)
			{
				j++;
				continue;
			}
			ll tmp=vec[i].second;
			kgj[j].second-=tmp;
			if(kgj[j].second<0)
			{
				vec[i].second=-kgj[j].second;
				kgj[j].second=0;
				j++;
			}
			else
			{
				vec[i].second=0;
				break;
			}
		}
	}
	for(int i=0;i<vec.size();i++)
		ans+=vec[i].second;
	printf("%lld\n",ans);
	return;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll T=1;
	while(T--)
		solve();
	return 0;
}

