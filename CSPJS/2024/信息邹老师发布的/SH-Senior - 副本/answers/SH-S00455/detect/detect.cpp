#include<bits/stdc++.h>
using namespace std;

const long long Inf=1e17+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

struct car
{
	ll d,v,a;
} c[100009];

bool chs[100009];
ll n,m,l,mxv,p[100009];

inline bool chka()
{
	for(int i=1;i<=n;i++)
		if(c[i].a!=0)
			return false;
	return true;
}

inline void solvea()
{
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(c[i].v>mxv&&c[i].d<=p[m])
			ans++;
	printf("%lld ",ans);
	if(ans==0)
		printf("%lld\n",m);
	else printf("%lld\n",m-1LL);
	return;
}

inline bool chkb()
{
	for(int i=1;i<=n;i++)
		if(c[i].a<=0)
			return false;
	return true;
}

inline void solveb()
{
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i].d>p[m])
			continue;
		ll va=c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d);
		if(va>mxv*mxv)
			ans++;
	}
	printf("%lld ",ans);
	if(ans==0)
		printf("%lld\n",m);
	else printf("%lld\n",m-1LL);
	return;
}

inline bool add()
{
	for(int i=n;i>=1;i--)
	{
		if(chs[i]==false)
		{
			chs[i]=true;
			return true;
		}
		else
		{
			chs[i]=false;
		}
	}
	return false;
}

inline void solvenr()
{
	memset(chs,false,sizeof(chs));
	ll answer=Inf,res=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i].d>p[m])
			continue;
		if(c[i].a>=0)
		{
			ll va=c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d);
			if(va>mxv*mxv)
			{
				res++;
			}
		}
		else
		{
			ll chkl;
			for(int j=1;j<=m;j++)
				if(p[j]>=c[i].d)
				{
					chkl=p[j];
					break;
				}
			ll va=c[i].v*c[i].v+2*c[i].a*(chkl-c[i].d);
			if(va>mxv*mxv)
			{
				res++;
			}
		}
	}
	while(add())
	{
		ll tmp=0;
		for(int i=1;i<=n;i++)
			if(chs[i]==true)
				tmp++;
		if(tmp>=answer)
			continue;
		ll ans=0,pos;
		for(int i=m;i>=1;i--)
			if(chs[i])
			{
				pos=i;
				break;
			}
		for(int i=1;i<=n;i++)
		{
			if(c[i].d>p[pos])
				continue;
			if(c[i].a>=0)
			{
				ll va=c[i].v*c[i].v+2*c[i].a*(p[pos]-c[i].d);
				if(va>mxv*mxv)
					ans++;
			}
			else
			{
				ll chkl=-1;
				for(int j=1;j<=m;j++)
					if(chs[j]&&p[j]>=c[i].d)
					{
						chkl=p[j];
						break;
					}
				if(chkl==-1)
					continue;
				ll va=c[i].v*c[i].v+2*c[i].a*(chkl-c[i].d);
				if(va>mxv*mxv)
				{
					ans++;
				}
			}
		}
		if(ans==res)
		{
			tmp=0;
			for(int i=1;i<=n;i++)
				if(chs[i])
					tmp++;
			answer=min(answer,tmp);
		}
	}
	printf("%lld %lld\n",res,m-answer);
	return;
}

inline void solve()
{
	scanf("%lld %lld %lld %lld",&n,&m,&l,&mxv);
	for(int i=1;i<=n;i++)
		scanf("%lld %lld %lld",&c[i].d,&c[i].v,&c[i].a);
	for(int i=1;i<=m;i++)
		scanf("%lld",&p[i]);
	if(chka())
		solvea();
	else if(chkb())
		solveb();
	else solvenr();
	return;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}

