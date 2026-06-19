#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,a[100009][4],ans=0;
map<ll,ll> cnt;
vector<ll> vec;

struct _STUD
{
	ll mx,sub,id;
	bool operator<(const _STUD&a)const
	{
		return mx>a.mx;
	}
} st[100009];

void solve()
{
	cnt.clear();
	vec.clear();
	ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		{
			scanf("%lld",&a[i][j]);
//			printf("%lld\n",a[i][j]);
		}
	for(int i=1;i<=n;i++)
	{
		ll tmp[3];
		for(int j=0;j<3;j++)
			tmp[j]=a[i][j+1];
		sort(tmp,tmp+3,greater<ll>());
//		for(int j=0;j<3;j++)
//			printf("%lld ",tmp[j]);
//		printf("\n");
		st[i].mx=tmp[0];
		if(st[i].mx==a[i][1])
			st[i].id=1LL;
		if(st[i].mx==a[i][2])
			st[i].id=2LL;
		if(st[i].mx==a[i][3])
			st[i].id=3LL;
		st[i].sub=tmp[0]-tmp[1];
//		printf("%lld %lld %lld\n",st[i].mx,st[i].id,st[i].sub);
	}
	sort(st+1,st+n+1);
	for(int i=1;i<=n;i++)
	{
		cnt[st[i].id]++;
		ans+=st[i].mx;
	}
//	printf("%lld %lld %lld\n",cnt[1],cnt[2],cnt[3]);
	ll pos=0;
	for(int i=1;i<=3;i++)
		if(cnt[i]>n/2)
		{
			for(int j=1;j<=n;j++)
				if(st[j].id==i)
					vec.push_back(st[j].sub);
			pos=i;
		}
	if(pos==0)
	{
		printf("%lld\n",ans);
		return;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<cnt[pos]-n/2;i++)
		ans-=vec[i];
	printf("%lld\n",ans);
	return;
} 

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}
