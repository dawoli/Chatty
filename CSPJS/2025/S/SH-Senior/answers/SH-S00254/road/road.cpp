#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
int n,m,k;
typedef pair<int,int> pii;
#define fi first
#define se second
struct p
{
	int u,v,w;
	friend bool operator <(p m,p n)
	{
		return m.w<n.w;
	}
} b[2000010],d[2000010],e[2000010];
int c[200010];
int vv[15][200010];
int u,v,w;
int fa[200010];
int siz[200010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	rep(i,1,m)
	{
		cin>>u>>v>>w;
		d[i].u=u,d[i].v=v,d[i].w=w;
	}
	sort(d+1,d+m+1);
	rep(i,1,k)
	{
		cin>>c[i];
		rep(j,1,n) cin>>vv[i][j];
	}
	int ans=0x3f3f3f3f3f3f3f3f,tp=0,cnt=0,al=0,nw=0;
	cnt=m;
	sort(d+1,d+cnt+1);
	tp=0;al=n;nw=0;
	rep(j,1,n) fa[j]=j,siz[j]=1;
	rep(j,1,cnt)
	{
		int fx=find(d[j].u),fy=find(d[j].v);
		if(fx==fy) continue;
		if(siz[fx]>siz[fy]) swap(fx,fy);
		fa[fx]=fy;
		siz[fy]+=siz[fx];
		++nw;tp+=d[j].w;
		e[nw]=d[j];
		if(nw==al-1) break;
	}
//	cout<<tp<<endl;
	ans=min(ans,tp); 
	rep(i,0,((1<<k)-1))
	{
		tp=0;cnt=n-1;al=n;nw=0;
		rep(j,1,cnt) b[j]=e[j];
		rep(j,1,k)
		{
			if(i&(1<<(j-1))) 
			{
				tp+=c[j];
				++al;
				rep(l,1,n)
				{
					b[++cnt].u=j+n;
					b[cnt].v=l;
					b[cnt].w=vv[j][l];
				}
			}
		}
		sort(b+1,b+cnt+1);
		rep(j,1,k+n) fa[j]=j,siz[j]=1;
		rep(j,1,cnt)
		{
			int fx=find(b[j].u),fy=find(b[j].v);
			if(fx==fy) continue;
			if(siz[fx]>siz[fy]) swap(fx,fy);
			fa[fx]=fy;
			siz[fy]+=siz[fx];
			++nw;tp+=b[j].w;
			if(nw==al-1) break;
		}
		ans=min(ans,tp); 
	}
	cout<<ans<<'\n'; 
}
