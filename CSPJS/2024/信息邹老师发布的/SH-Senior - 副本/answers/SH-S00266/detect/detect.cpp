#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::clog;
using std::endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=100009;
int v[N],a[N],d[N];
int p[N],resl[N],resr[N];
int n,m,L,V;
bool check(int c,int id) {
	//是否超速
	if(0ll+1ll*v[c]*v[c]+2ll*a[c]*(p[id]-d[c])>V*V) return true;
	else return false;
}
struct SEG {
	int l,r;
	const bool operator< (const SEG& a) const {
		return r<a.r||r==a.r&&l<a.l;
	}
} seg[N];
int nseg;
void solve() {
	cin>>n>>m>>L>>V,nseg=0;
	for(int i=1; i<=n; i++) cin>>d[i]>>v[i]>>a[i];
	for(int i=1; i<=m; i++) cin>>p[i];
	for(int i=1; i<=n; i++) {
		if(a[i]>0) {
			int l=std::lower_bound(p+1,p+1+m,d[i])-p,r=m,mid,ans=m+1;
			while(l<=r) {
				mid=l+(r-l)/2;
				if(check(i,mid)) r=mid-1,ans=mid;
				else l=mid+1;
			}
			resl[i]=ans,resr[i]=m;
		} else if(a[i]<0) {
			int l=resl[i]=std::lower_bound(p+1,p+1+m,d[i])-p,r=m,mid,ans=0;
			while(l<=r) {
				mid=l+(r-l)/2;
				if(check(i,mid)) l=mid+1,ans=mid;
				else r=mid-1;
			}
			resr[i]=ans;
		} else if(a[i]==0) {
			resl[i]=std::lower_bound(p+1,p+1+m,d[i])-p;
			if(v[i]>V) resr[i]=m;
		}
	}
	int cnt=0,ans=0,l=0,r=m+1;
	for(int i=1; i<=n; i++) if(resl[i]<=resr[i]) {
			cnt++;
			seg[++nseg]=(SEG) {
				resl[i],resr[i]
			};
		}

//	clog<<nseg<<endl;
	std::sort(seg+1,seg+1+nseg);
	//最小点集区间覆盖问题？
	//每次选择最小为解决区间的最右端？逐步调整？
	//假的
	int tans=0;
	for(int i=1,r=0; i<=nseg; i++) {
//		clog<<nseg<<' '<<i<<endl;
//		clog<<seg[i].l<<'~'<<seg[i].r<<endl;
		if(seg[i].l<=r) continue;
		else tans++,r=seg[i].r;
	}
	ans=std::max(ans,tans);
	for(int i=1,r=0; i<=nseg; i++) {
		std::swap(seg[i].l,seg[i].r);
		seg[i].l=m-seg[i].l+1,seg[i].r=m-seg[i].r+1;
	}
	std::sort(seg+1,seg+1+nseg);
	//最小点集区间覆盖问题？
	//每次选择最小为解决区间的最右端？逐步调整？
	//假的
	tans=0;
	for(int i=1,r=0; i<=nseg; i++) {
//		clog<<nseg<<' '<<i<<endl;
//		clog<<seg[i].l<<'~'<<seg[i].r<<endl;
		if(seg[i].l<=r) continue;
		else tans++,r=seg[i].r;
	}
//	clog<<tans<<endl;
	ans=std::min(ans,tans);
	cout<<cnt<<' ';
	cout<<m-ans<<'\n';
}
int main() {
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("F:\\CSP-S\\detect\\detect3.in","r",stdin);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	cout.flush();
	return 0;
}

