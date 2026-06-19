#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=100005;
int _,n,m,len,mxv,d[N],v[N],a[N],p[N],cnt[N],vis[N];
pii q[N];
bool cmp(pii a,pii b)
{
	if(a.se!=b.se) return a.se<b.se;
	return a.fi<b.fi;
}
void solve()
{
	cin>>n>>m>>len>>mxv;
	for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i],q[i].fi=0,q[i].se=0,cnt[i]=0;
	for(int i=1;i<=m;i++) cin>>p[i],vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(v[i]>mxv)
			{
				if(d[i]<=p[m])
				{
					q[i].fi=lower_bound(p+1,p+m+1,d[i])-p;
					q[i].se=m;
				}
			}
		}
		if(a[i]>0)
		{
			if(v[i]>mxv)
			{
				if(d[i]<=p[m])
				{
					q[i].fi=lower_bound(p+1,p+m+1,d[i])-p;
					q[i].se=m;
				}
				continue;
			}
			int pos=(int)((double)d[i]+(double)(mxv*mxv-v[i]*v[i])/2.0/a[i]);
			if(pos<p[m])
			{
				q[i].fi=upper_bound(p+1,p+m+1,pos)-p;
				q[i].se=m;
			}
		}
		if(a[i]<0)
		{
			if(v[i]<=mxv) continue;
			if(d[i]>p[m]) continue;
			int pos=(int)((ceil)((double)d[i]+(double)(mxv*mxv-v[i]*v[i])/2.0/a[i]));
			int lpos=lower_bound(p+1,p+m+1,d[i])-p;
			if(p[lpos]>=pos) continue;
			q[i].fi=lpos;
			q[i].se=lower_bound(p+1,p+m+1,pos)-p-1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i].fi!=0&&q[i].se!=0) ans++;
	}
	cout<<ans<<' ';
	int c=0,nw=0;
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if((!q[i].fi)&&(!q[i].se)) continue;
		if(!nw) nw=q[i].se;
		else if(q[i].fi>nw) nw=q[i].se;
		vis[nw]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(!vis[i]) c++;
	}
	cout<<c<<endl;
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while(_--) solve();
	return 0;
}
