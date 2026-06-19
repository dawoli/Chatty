#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=1e6+10;
int t,n,m,ans=0,num,cnt[M];
ll tot,mx,p[N];
struct X{
	ll d,v,a,l,r;
	int k;
	void find() {
		if(a<0) {
			if(v<=mx) l=r=-1;
			else {
				l=d;
				r=(mx*mx-v*v)/(2*a);++r;
				if(v*v+2*a*r<=mx*mx) r--;
				if(v*v+2*a*r<=mx*mx) r--;
				if(v*v+2*a*r<=mx*mx) r--;
				r+=d;
				if(r>=tot) r=tot;
			}
		}
		else if(a==0) {
			if(v<=mx) l=r=-1;
			else l=d,r=tot;
		}
		else {
			if(v>mx) l=d,r=tot;
			else {
				l=(mx*mx-v*v)/(2*a);--l;
				if(v*v+2*a*l<=mx*mx) l++;
				if(v*v+2*a*l<=mx*mx) l++;
				if(v*v+2*a*l<=mx*mx) l++;
				l+=d;
				if(l>tot) l=r=-1;
				else r=tot;
			}
		}
	}
}c[N];
struct A{
	int l,r;
	bool operator < (const A& p) const {
		if (l!=p.l) return l<p.l;
		return r>p.r;
	}
}u[N],v[N];
int f[M],t1,t2,mn,tmp;
int query(int pos) {
	if(pos<=0) return 0;
	int sum=0;
	for(int i=pos;i;i-=i&(-i)) sum+=f[i];
	return sum;
}
void add(int pos) {
	if(pos==0) return;
	for(int i=pos;i<=tot;i+=i&(-i)) f[i]++;
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%lld%lld",&n,&m,&tot,&mx);ans=0;
		int z=1;
		for(int i=1;i<=n;++i) scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a),c[i].find(),c[i].k=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=m;++i) scanf("%lld",&p[i]),cnt[p[i]]=1;
		for(int i=1;i<=tot;++i) cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;++i) {
//			printf("%d %d\n",c[i].l,c[i].r);
			if(c[i].l!=-1&&c[i].r!=-1&&((c[i].l==0&&cnt[c[i].r]>0)||(c[i].l>0&&cnt[c[i].r]-cnt[c[i].l-1]>0))) {
				c[i].k=1;
				++ans;
			}
		}
		num=0;
		for(int i=1;i<=n;++i)
			if(c[i].k==1&&c[i].a<0)
				z=0;
		if(ans==0) num=0;
		else if(z==1) num=1;
		else {
			num=0;
			t1=t2=0;
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;++i)
				if(c[i].k==1)
					v[++t2]=(A){c[i].l,c[i].r};
			sort(v+1,v+t2+1);
			mn=0x3f3f3f3f;
			for(int i=t2;i>=1;--i)
				if(mn>v[i].r)
					u[++t1]=v[i],mn=v[i].r;
			sort(u+1,u+t1+1);
			for(int i=1;i<=t1;++i)
				if(query(u[i].r)-query(u[i].l-1)==0) {
					tmp=lower_bound(p+1,p+m+1,u[i].r+1)-p-1;
					add(p[tmp]);
					++num;
				}
		}
		printf("%d %d\n",ans,m-num);
	}
	return 0;
}
