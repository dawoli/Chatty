#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define eps 1e-8
#define db double
#define ll long long
int T,n,m,L,cnt,d[N],p[N];
db V,v[N],a[N],t,x;
int ov[N],l[N],r[N];
inline int before(db x){//not equal
	static int l,r,mid;l=1,r=m;
	while(l<=r){
		mid=(l+r)>>1;
		if(x>p[mid]+eps)l=mid+1;
		else r=mid-1;
	}
	return r;
}
inline int beforeeq(db x){//can equal
	static int l,r,mid;l=1,r=m;
	while(l<=r){
		mid=(l+r)>>1;
		if(x>p[mid]-eps)l=mid+1;
		else r=mid-1;
	}
	return r;
}
namespace solver{
	int n,l[N],r[N],s[N<<1],m;
	struct st{int l,r;}k[N];
	inline bool cmp(const st&a,const st&b){return a.r==b.r?a.l<b.l:a.r<b.r;}
	int solve(){
		for(int i=1;i<=n;++i)s[i]=l[i],s[i+n]=r[i];
		sort(s+1,s+n+n+1);m=unique(s+1,s+n+n+1)-s-1;
		for(int i=1;i<=n;++i){
			l[i]=lower_bound(s+1,s+m+1,l[i])-s;
			r[i]=lower_bound(s+1,s+m+1,r[i])-s;
			k[i].l=l[i],k[i].r=r[i];
		}
		sort(k+1,k+n+1,cmp);
		int res=0,g=-1;
		for(int i=1;i<=n;++i){
			if(g<k[i].l)g=k[i].r,++res;
		}
		return res;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%lf",&n,&m,&L,&V);
		for(int i=1;i<=n;++i)scanf("%d%lf%lf",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&p[i]);
		cnt=0;
		for(int i=1;i<=n;++i){
			if(fabs(a[i])<eps){
				if(v[i]>V+eps&&d[i]<=p[m]){
					ov[i]=1;l[i]=before(d[i])+1;r[i]=m;
					++cnt;
				}else ov[i]=l[i]=r[i]=0;
			}
			else if(a[i]>0){
				if(v[i]>V+eps){
					if(d[i]<=p[m]){
						ov[i]=1;l[i]=before(d[i])+1;r[i]=m;
						++cnt;
					}else ov[i]=l[i]=r[i]=0;
					continue;
				}
				t=max(0.,(V-v[i])/a[i]);
				x=d[i]+v[i]*t+a[i]*t*t/2;
				if(x<p[m]-eps){
					ov[i]=1;l[i]=beforeeq(x)+1;r[i]=m;
					++cnt;
				}else ov[i]=l[i]=r[i]=0;
			}
			else{
				if(v[i]<V+eps){ov[i]=l[i]=r[i]=0;continue;}
				t=(V-v[i])/a[i];
				x=d[i]+v[i]*t+a[i]*t*t/2;
				l[i]=before(d[i])+1;
				r[i]=before(x);
				if(l[i]<=r[i])ov[i]=1,++cnt;
				else ov[i]=l[i]=r[i]=0;
			}
		}
		solver::n=cnt;
		for(int i=1,j=0;i<=n;++i)if(ov[i]){
			++j;solver::l[j]=l[i],solver::r[j]=r[i];
		}
		printf("%d %d\n",cnt,m-solver::solve());
	}
	return 0;
}
