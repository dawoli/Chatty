/*

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,m,k,V,tot,d[N],v[N],a[N],p[N];
pair<ll,ll>line[N];
bool check(ll v,ll a,ll x)
{
	return v*v+2*a*x>V*V;
}
bool cmp(pair<ll,ll>x,pair<ll,ll>y)
{
	if (x.first!=y.first) return x.first<y.first;
	return x.second>y.second;
}
ll read()
{
	ll res=0,x=1;
	char ch=getchar();
	while (ch<'0'||'9'<ch)
	{
		if (ch=='-') x=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*x;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while (T--)
	{
		n=read(),m=read(),k=read(),V=read();
		for (int i=1;i<=n;i++) d[i]=read(),v[i]=read(),a[i]=read();
		for (int i=1;i<=m;i++) p[i]=read();
		sort(p+1,p+m+1);
		tot=0;
		for (int i=1;i<=n;i++) // car -> line
		{
			if (p[m]<d[i]) continue;
			if (a[i]>=0)
			{
				if (!check(v[i],a[i],p[m]-d[i])) continue;
				line[++tot].second=m;
				ll l=lower_bound(p+1,p+m+1,d[i])-p,r=m,res;
				while (l<=r)
				{
					ll mid=(l+r) >> 1;
					if (check(v[i],a[i],p[mid]-d[i])) line[tot].first=mid,r=mid-1;
					else l=mid+1;
				}
			}
			else
			{
				if (v[i]<=V) continue;
				ll l=lower_bound(p+1,p+m+1,d[i])-p;
				if (!check(v[i],a[i],p[l]-d[i])) continue;
				line[++tot].first=l;
				ll r=m;
				while (l<=r)
				{
					ll mid=(l+r) >> 1;
					if (check(v[i],a[i],p[mid]-d[i])) line[tot].second=mid,l=mid+1;
					else r=mid-1;
				}
			}
		}
		sort(line+1,line+tot+1,cmp);
		ll ans=0,now=k+1;
		for (int i=tot;i;i--)
		{
			if (line[i].second>=now) continue;
			now=line[i].first,ans++;
		}
		cout << tot << ' ' << (m-ans) << endl;
	}
	return 0;
}
