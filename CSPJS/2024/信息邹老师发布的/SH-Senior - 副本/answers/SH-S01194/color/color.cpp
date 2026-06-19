#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5,INF=1e14;
int n,tot;
long long a[maxn];
long long lisan[maxn];
int id[maxn];
struct TREE{
	int l,r;
	long long val,lazy;
	void tag(long long x)
	{
		val+=x;
		lazy+=x;
	}
}t[maxn<<2];
void pushup(int i){t[i].val=max(t[i<<1].val,t[i<<1|1].val);}
void pushdown(int i)
{
	t[i<<1].tag(t[i].lazy);
	t[i<<1|1].tag(t[i].lazy);
	t[i].lazy=0;
}
void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].lazy=0;
	if (l==r)
	{
		t[i].val= l==0?0:-INF;
		return ;
	}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	pushup(i);
}
void update(int i,int k,long long v)
{
	if (t[i].l>k||t[i].r<k)	return ;
	if (t[i].l==t[i].r)	{t[i].val=max(t[i].val,v);return ;}
	pushdown(i);
	update(i<<1,k,v);
	update(i<<1|1,k,v);
	pushup(i);
}
long long query(int i,int k)
{
	if (t[i].l>k||t[i].r<k)	return -INF;
	if (t[i].l==t[i].r)	return t[i].val;
	pushdown(i);
	return max(query(i<<1,k),query(i<<1|1,k));
}
void solve()
{
//	init...
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		lisan[i]=a[i];
	}
	sort (lisan+1,lisan+n+1);
	tot=unique(lisan+1,lisan+n+1)-lisan-1;
	for (int i=1;i<=n;i++)
		id[i]=lower_bound(lisan+1,lisan+tot+1,a[i])-lisan;
	build(1,0,tot);//zhu yi shi 0!
	for (int i=2;i<=n;i++)
	{
		long long te=max(query(1,id[i])+a[i],t[1].val);
		t[1].tag(a[i]==a[i-1]?a[i]:0);
		update(1,id[i-1],te);
	}
	printf("%lld\n",t[1].val);
}
int main()
{
//	freopen("color2.in","r",stdin);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;scanf("%d",&T);
	while (T--)	solve();
	return 0;
}
