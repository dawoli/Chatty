#define I using
#define love namespace
#define Poncirus_forever std

	I love Poncirus_forever;

#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define in(x) scanf("%lld",&x)
const ll N=1e4+4;
const double mini=0.000000001;

ll T,n,m,L,V,ces[N],hd[N],nxt[N],to[N],crim[N],tot;
ll h2[N],nx2[N],to2[N],tot2;
bool vic[N],vis[N];
vector< pair<ll,ll> > vec;
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	in(T);
	while(T--)
	{
		tot=tot2=0;
		memset(hd,0,sizeof hd);
		memset(nxt,0,sizeof nxt);
		memset(to,0,sizeof to);
		memset(h2,0,sizeof h2);
		memset(nx2,0,sizeof nx2);
		memset(to2,0,sizeof to2);
		memset(ces,0,sizeof ces);
		memset(crim,0,sizeof crim);
		memset(vis,0,sizeof vis);
		memset(vic,0,sizeof vic);
		vec.clear();
		vec.push_back(make_pair(-2,-2));
		in(n),in(m),in(L),in(V);
//		if(n>1e4||m>1e4) continue;
		for(ll i=1;i<=n;i++)
		{
			ll x0,v0,a,lich;
			in(x0),in(v0),in(a);
			if(a==0)
			{
				if(v0>V) vec.push_back(make_pair(x0,L));
				continue;
			}
			ll start,end;
			if(a<0) lich=min(lich,x0+v0*v0/(-2*a));
			
			double ex=1.0*x0+1.0*(V*V-v0*v0)/(2.0*a);
			//达V时的位移 
			if(ex-mini<x0&&a>0) start=x0,end=L;
			else if(ex-mini<x0&&a<0) continue;
			else if(ex-mini<=L&&a>0) start=ceil(ex+mini),end=L;
			else if(a<0) start=x0,end=floor(ex-mini);
			else continue;
			vec.push_back(make_pair(start,end));
		}
		for(ll i=1;i<=m;i++)
		{
			in(ces[i]);
			for(ll j=1;j<vec.size();j++)
			{
				if(vec[j].first<=ces[i]&&ces[i]<=vec[j].second)
				{
//					printf("%d shuyu [%d,%d]\n",ces[i],vec[j].first,vec[j].second);
					nxt[++tot]=hd[j];
					hd[j]=tot;
					to[tot]=i;
					
					nx2[++tot2]=h2[i];
					h2[i]=tot2;
					to2[tot2]=j;
					
					crim[i]++;
				}
			}
		}
		ll ans1=0;
		for(ll i=1;i<vec.size();i++)
		{
			if(hd[i]) ans1++;
//			printf("[%d,%d]\n",vec[i].first,vec[i].second);
//			for(ll j=hd[i];j;j=nxt[j]) printf("%d ",to[j]);
//			printf("\n");
		}
		printf("%d ",ans1);
		n=vec.size()-1;
		ll tu=0,ans2=0;
		while(tu<=ans1)
		{
			ll u=0,yyy=0;
			for(ll i=1;i<=m;i++)
				if(vic[i]==0&&crim[i]>yyy) u=i,yyy=crim[i];
			if(u==0) break;
			vic[u]=1;
			ans2++;
			for(ll i=h2[u];i;i=nx2[i])
			{
				ll v=to2[i];
				if(vis[v]==0)
				{
					tu++;
					vis[v]=1;
					for(ll k=hd[v];k;k=nxt[k]) crim[to[k]]--;
				}
			}
			
		}
		printf("%d\n",m-ans2);
		
	}
	return 0;
}
/*
writing an O(n^2) code
im totally without hope
10 years of OI turn into a chang of empty
im leaving chang with pity
all because not hard-working adequately

	hai bu shi yin wei zi ji bu gou nu li

idiot上司
我都知道谁超速了还测什么
不把员工当人

提前让我适应程序猿职场
出题人用心良苦 
*/

