#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10,INF=1e18;
struct frac{ll p,q;};
const frac fINF={INF,1};
frac simp(ll num1,ll num2)
{
	ll gcd=__gcd(num1,num2);
	num1/=gcd;
	num2/=gcd;
	return {num1,num2};
}
frac operator + (const frac &f1,const frac &f2){return simp(f1.p*f2.q+f2.p*f1.q,f1.q*f2.q);}
frac operator - (const frac &f1,const frac &f2){return simp(f1.p*f2.q-f2.p*f1.q,f1.q*f2.q);}
frac operator * (const frac &f1,const frac &f2){return simp(f1.p*f2.p,f1.q*f2.q);}
frac operator / (const frac &f1,const frac &f2){return simp(f1.p*f2.q,f1.q*f2.p);}
bool operator == (const frac &f1,const frac &f2)
{
	if(f1.p==f2.p && f1.q==f2.q) return 1;
	else return 0;
}
bool operator > (const frac &f1,const frac &f2)
{
	ll a1=f1.p/f1.q,b1=f1.p%f1.q,c1=f1.q;
	ll a2=f2.p/f2.q,b2=f2.p%f2.q,c2=f2.q;
	if(a1>a2) return 1;
	else if(a1<a2) return 0;
	else
	{
		b1*=c2;
		b2*=c1;
		if(b1>b2) return 1;
		else return 0;
	}
}
bool operator < (const frac &f1,const frac &f2)
{
	ll a1=f1.p/f1.q,b1=f1.p%f1.q,c1=f1.q;
	ll a2=f2.p/f2.q,b2=f2.p%f2.q,c2=f2.q;
	if(a1<a2) return 1;
	else if(a1>a2) return 0;
	else
	{
		b1*=c2;
		b2*=c1;
		if(b1<b2) return 1;
		else return 0;
	}
}
bool operator >= (const frac &f1,const frac &f2)
{
	if(f1==f2) return 1;
	ll a1=f1.p/f1.q,b1=f1.p%f1.q,c1=f1.q;
	ll a2=f2.p/f2.q,b2=f2.p%f2.q,c2=f2.q;
	if(a1>a2) return 1;
	else if(a1<a2) return 0;
	else
	{
		b1*=c2;
		b2*=c1;
		if(b1>b2) return 1;
		else return 0;
	}
}
bool operator <= (const frac &f1,const frac &f2)
{
	if(f1==f2) return 1;
	ll a1=f1.p/f1.q,b1=f1.p%f1.q,c1=f1.q;
	ll a2=f2.p/f2.q,b2=f2.p%f2.q,c2=f2.q;
	if(a1<a2) return 1;
	else if(a1>a2) return 0;
	else
	{
		b1*=c2;
		b2*=c1;
		if(b1<b2) return 1;
		else return 0;
	}
}
struct Node
{
	ll v,a;
	frac d,st,en;
	bool inc_st,inc_en;
}car[N];
ll T,n,m,L,V,ans1,ans2;
frac pos[N];
bool on[N];
vector<ll> vec[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans1=0;
		ans2=0;
		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&car[i].d.p,&car[i].v,&car[i].a);
			car[i].d.q=1;
			car[i].inc_st=1;
			car[i].inc_en=1;
			if(car[i].a>0)
			{
				if(car[i].v>V)
				{
					car[i].st=car[i].d;
					car[i].en=fINF;
					car[i].inc_en=0;
				}
				else
				{
					car[i].st=simp(V*V-car[i].v*car[i].v,2*car[i].a);
					car[i].st=car[i].st+car[i].d;
					car[i].en=fINF;
					car[i].inc_st=0;
					car[i].inc_en=0;
				}
			}
			else if(car[i].a==0)
			{
				if(car[i].v>V)
				{
					car[i].st=car[i].d;
					car[i].en=fINF;
					car[i].inc_en=0;
				}
				else
				{
					car[i].st={0,1};
					car[i].en={0,1};
					car[i].inc_st=0;
					car[i].inc_en=0;
				}
			}
			else
			{
				if(car[i].v>V)
				{
					car[i].st=car[i].d;
					car[i].en=simp(V*V-car[i].v*car[i].v,2*car[i].a);
					car[i].en=car[i].en+car[i].d;
					car[i].inc_en=0;
				}
				else
				{
					car[i].st={0,1};
					car[i].en={0,1};
					car[i].inc_st=0;
					car[i].inc_en=0;
				}
			}
		}
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld",&pos[i].p);
			pos[i].q=1;
		}
		sort(pos+1,pos+m+1);
//		for(ll i=1;i<=n;i++) printf("%lld ",pos[i].p);
//		printf("\n");
//		for(ll i=1;i<=n;i++)
//		{
//			printf("%lld: ",i);
//			if(car[i].inc_st) printf("[");
//			else printf("(");
//			printf("%lld/%lld,%lld/%lld",car[i].st.p,car[i].st.q,car[i].en.p,car[i].en.q);
//			if(car[i].inc_en) printf("]");
//			else printf(")");
//			printf("\n");
//		}
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
			{
				bool flag1=(pos[j]>car[i].st && pos[j]<car[i].en);
				bool flag2=(car[i].inc_st && pos[j]==car[i].st);
				bool flag3=(car[i].inc_en && pos[j]==car[i].en);
				if(flag1 || flag2 || flag3) vec[i].push_back(j);
			}
//		for(ll i=1;i<=n;i++)
//		{
//			for(auto j:vec[i]) printf("%lld ",j);
//			printf("\n");
//		}
		for(ll i=1;i<=n;i++)
			if(!vec[i].empty()) ans1++;
		printf("%lld ",ans1);
		for(ll i=0;i<=(1ll<<m)-1;i++)
		{
			ll temp=i,now=1,cnt=0;
			bool flag=1;
			while(temp)
			{
				if(temp%2) on[now]=1;
				else
				{
					on[now]=0;
					cnt++;
				}
				temp/=2;
				now++;
			}
			if(cnt<=ans2) continue;
			for(ll j=1;j<=n;j++)
				if(!vec[j].empty())
				{
					bool flag_=0;
					for(auto k:vec[j]) flag_|=on[k];
					if(!flag_)
					{
						flag=0;
						break;
					}
				}
			if(flag) ans2=max(ans2,cnt);
		}
		printf("%lld\n",ans2);
	}
	return 0;
}
