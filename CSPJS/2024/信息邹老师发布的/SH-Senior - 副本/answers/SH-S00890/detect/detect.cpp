#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<48||ch>57) {if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const long long N=100005,LEN=1000100;
long long T,n,m,L,V;
long long d[N],v[N],a[N];
long long p[N],c[N+10];
long long ans1;
struct node
{
	long long l,r;
} s[N];
long long tot;
long long get(long long l,long long r,long long x)
{
	long long mid,ans=m+1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(p[mid]>=x) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
long long num,nd,x,y,nv2;
bool cmp(node a,node b)
{
	if(a.r!=b.r) return a.r<b.r;
	return a.l>b.l;
}
inline long long lowbit(long long x){return x&(-x);}
void add(long long x,long long v)
{
	while(x<N) c[x]+=v,x+=lowbit(x);
}
long long query(long long x)
{
	long long sum=0;
	while(x) sum+=c[x],x-=lowbit(x);
	return sum;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(c,0,sizeof(c));
		ans1=0;tot=0;
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;++i) d[i]=read(),v[i]=read(),a[i]=read();
		for(int i=1;i<=m;++i) p[i]=read();
		for(int i=1;i<=n;++i)
		{
			if(a[i]==0)
			{
				if(v[i]>V&&d[i]<=p[m])
				{
					++ans1;
					x=get(1,m,d[i]);
					s[++tot].l=x;s[tot].r=m;
				}
				continue;
			}
			if(a[i]>0)
			{
				if(d[i]>p[m]) continue;
				nv2=v[i]*v[i]+2*a[i]*(p[m]-d[i]);
				if(nv2>V*V)
				{
					++ans1;
					++tot;s[tot].r=m;
					int l=1,r=m,mid;
					while(l<=r)
					{
						mid=l+r>>1;
						if(p[mid]<d[i]) l=mid+1;
						if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V) s[tot].l=mid,r=mid-1;
						else l=mid+1;
					}
				}
				continue;
			}
			if(v[i]<=V) continue;
			nd=ceil((V*V-v[i]*v[i])*1.0/(2*a[i]));
			x=get(1,m,d[i]),y=get(1,m,d[i]+nd);
//			cout<<i<<" "<<d[i]<<" "<<d[i]+nd<<" "<<x<<" "<<y<<"\n";
			if(x!=y)
			{
				++ans1;
				--y;
				if(x>y) swap(x,y);
				s[++tot].l=x;s[tot].r=y;
			}
		}
		sort(s+1,s+1+tot,cmp);
		for(int i=1;i<=tot;++i)
		{
			if(query(s[i].r)-query(s[i].l-1)>0) continue;
			add(s[i].r,1);
		}
		cout<<ans1<<" "<<m-query(N)<<"\n";
	}
	return 0;
}
