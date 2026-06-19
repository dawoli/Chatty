#include<bits/stdc++.h>
using namespace std;
//#define int long long 
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef pair<int,int> pii;
int n,m,x,y,a[200010],L,V,tst=0,cnt=0,tcnt=0,ans1=0,nn=0,tmp=0,tp=0,nw=0;
double lstd;
struct p
{
	int d,v,a;
}b[200010];
double l[200010],r[200010];
int pl[200010],pr[200010];
int p[200010];
struct q
{
	int l,r;
	friend bool operator <(q m,q n){if(m.r!=n.r) return m.r<n.r;return m.l>n.l;}
} d[200010];
double lsh[1000010];
bool vis[200010];
double eps=1e-7;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>tst;
	while(tst--)
	{
		cnt=0;
		cin>>n>>m>>L>>V;
		rep(i,1,n) cin>>b[i].d>>b[i].v>>b[i].a,vis[i]=0;
		rep(i,1,n)
		{
			if(b[i].a<0)
			{
				if(b[i].v<=V) l[i]=r[i]=-2;
				else
				{
					lstd=1.0*(V*V-b[i].v*b[i].v)/2/b[i].a;
					if(lstd+b[i].d>L) l[i]=b[i].d,r[i]=L;
					else
					{
						l[i]=b[i].d;
						r[i]=lstd+b[i].d-eps;
					}
				}
			}
			else if(b[i].a==0)
			{
				if(b[i].v<=V) l[i]=r[i]=-2;
				else  l[i]=b[i].d,r[i]=L;
			}
			else
			{
				if(b[i].v>V) l[i]=b[i].d,r[i]=L;
				else
				{
					lstd=1.0*(V*V-b[i].v*b[i].v)/2/b[i].a;
					if(lstd+b[i].d>L) l[i]=r[i]=-2;
					else
					{
						l[i]=b[i].d+lstd+eps;
						r[i]=L;
					}
				}
			}
		}
		rep(i,1,m) cin>>p[i];
		rep(i,1,m) lsh[++cnt]=p[i];
		rep(i,1,n)
		{
			if(l[i]<=-1&&r[i]<=-1) continue;
			lsh[++cnt]=l[i];
			lsh[++cnt]=r[i];
		}
		sort(lsh+1,lsh+cnt+1);
		tcnt=unique(lsh+1,lsh+cnt+1)-lsh-1;
		rep(i,1,m) p[i]=lower_bound(lsh+1,lsh+cnt+1,p[i])-lsh;
		rep(i,1,n)
		{
			if(l[i]<=-1&&r[i]<=-1) continue;
			pl[i]=lower_bound(lsh+1,lsh+cnt+1,l[i])-lsh;
			pr[i]=lower_bound(lsh+1,lsh+cnt+1,r[i])-lsh;
		}
		ans1=0;
		rep(i,1,n)
		{
			if(l[i]<=-1&&r[i]<=-1) continue;
			int it=lower_bound(p+1,p+m+1,pl[i])-p;
			if(it<=m&&p[it]<=pr[i]) vis[i]=1,ans1++;
		}
		cout<<ans1<<" ";
		nn=0;
		rep(i,1,n)
		{
			if(vis[i])
			{
				d[++nn].l=pl[i];
				d[nn].r=pr[i];
			}
		}
		sort(d+1,d+nn+1);
		tmp=0;nw=-1;
		rep(i,1,nn)
		{
			if(nw>d[i].r||nw<d[i].l) 
			{
				tp=upper_bound(p+1,p+m+1,d[i].r)-p-1;
				nw=p[tp];
				++tmp;
			}
			else continue;
		}
		cout<<m-tmp<<endl;
	}
	
} 
