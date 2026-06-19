#include<bits/stdc++.h>
#define Hatsune return
#define Miku 0
using namespace std;

typedef long long ll;
const int N=1e5+10,LEN=1e6+10;

ll n,m,P,V,d[N],p[N],a[N],v[N],nxt[LEN],fang[N];
ll ans,Vfang;
ll R[N];

void qwq(ll D)
{
	if(nxt[D]==m+1) return;
	ans++;
	R[m]=max(R[m],nxt[D]);
}

void add(ll LL,ll RR)
{
	ans++;
	R[RR]=max(R[RR],LL);
}

/*
s=x-d[i]
v[i]^2+2a[i]s > V^2 ok
*/

bool check(ll i,ll x)
{
	return fang[i]+2*a[i]*(x-d[i])>Vfang;
}

void solve()
{
	ans=0;
	cin>>n>>m>>P>>V;nxt[P+1]=m+1;Vfang=V*V;
	for(ll i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i],fang[i]=v[i]*v[i];
	for(ll i=P;i>=0;i--) nxt[i]=0;
	for(ll i=1;i<=m;i++) cin>>p[i],nxt[p[i]]=i,R[i]=0;
	for(ll i=P;i>=0;i--)
	{
		if(!nxt[i]) nxt[i]=nxt[i+1];
	}
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(v[i]>V) qwq(d[i]);
			continue;
		}
		if(a[i]>0)
		{
			int l=nxt[d[i]],r=m,mid,res=0;
			while(l<=r)
			{
				mid=l+r>>1;
				if(check(i,p[mid])) res=mid,r=mid-1;
				else l=mid+1;
			}
			if(res) qwq(p[res]);
			continue;
		}
		int l=nxt[d[i]],r=m,mid,res=0;
		while(l<=r)
		{
			mid=l+r>>1;
			if(check(i,p[mid])) res=mid,l=mid+1;
			else r=mid-1;
		}
		if(res) add(nxt[d[i]],res);
		continue;
	}
	ll ans2=0,now=0;
	for(ll i=1;i<=m;i++)
	{
		if(R[i]>now) now=i,ans2++;
	}
	cout<<ans<<" "<<m-ans2<<"\n";
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--) solve();
	Hatsune Miku;
}
