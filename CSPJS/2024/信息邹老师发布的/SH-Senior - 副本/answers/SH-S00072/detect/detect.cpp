#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-6;
const ll N=1e5+9;
ld p[N];
ll T,d[N],v[N],a[N],vst[N],OK[N],ans;
struct Node
{
	ld l,r;
}x[N];
bool cmp(const Node m,const Node n)
{
	if(m.r==n.r)return m.l<n.l;
	return m.r<n.r;
}
void MAIN()
{
	ll n,m,LL,V;ans=0;
	scanf("%lld%lld%lld%lld",&n,&m,&LL,&V);
	for(ll i=1;i<=n;i++)scanf("%lld %lld %lld",&d[i],&v[i],&a[i]);
	for(ll i=1;i<=m;i++)cin>>p[i];
	sort(p+1,p+m+1);
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(v[i]>V)x[i].l=d[i],x[i].r=LL;
			else x[i].l=x[i].r=-1;
		}
		else if(a[i]<0)
		{
			if(v[i]<=V)x[i].l=x[i].r=-1;
			else
			{
				x[i].l=d[i];
				x[i].r=d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])-eps;
			}
		}
		else if(a[i]>0)
		{
			if(v[i]>V)x[i].l=d[i],x[i].r=LL;
			else
			{
				x[i].l=d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])+eps;
				x[i].r=LL;
			}
		}
	}
	ll L,R;
	for(ll i=1;i<=n;i++)
	{
		L=1,R=m;
		ll k1=0,k2=m+1;
		while(L<=R)
		{
			ll mid=(L+R)>>1;
			if(p[mid]<=x[i].r)L=mid+1,k1=mid;
			else R=mid-1;
		}
		L=1,R=m;
		while(L<=R)
		{
			ll mid=(L+R)>>1;
			if(p[mid]>=x[i].l)R=mid-1,k2=mid;
			else L=mid+1;
		}
		if(k1>=k2)vst[i]=1,ans++;
		else vst[i]=0;
	}
	if(ans==0)
	{
		cout<<"0 "<<m<<endl;
		return;
	}
	for(ll i=1;i<=n;i++)if(vst[i]==0)x[i].l=x[i].r=-1;
	sort(x+1,x+n+1,cmp);
	ll k,k_,now,sum=0;
	for(ll i=1;i<=n;i++)
	{
		if(x[i].l!=-1&&x[i].r!=-1)
		{
			k=i;
			break;
		}
	}
	L=1,R=m,k_=0;
	while(L<=R)
	{
		ll mid=(L+R)/2;
		if(p[mid]<=x[k].r)L=mid+1,k_=mid;
		else R=mid-1;
	}
	memset(OK,0,sizeof(OK));
	now=k_;OK[k_]=1;
	for(ll i=k+1;i<=n;i++)
	{
		if(p[now]<x[i].l)
		{
			while(p[now+1]<=x[i].r&&now<=m)now++;
			if(now==m+1)now=m;
		}
		OK[now]=1;
	}
	for(ll i=k_;i<=m;i++)sum+=OK[i];
	printf("%lld %lld\n",ans,m-sum);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&T);
	while(T--)MAIN();
	return 0;
}
