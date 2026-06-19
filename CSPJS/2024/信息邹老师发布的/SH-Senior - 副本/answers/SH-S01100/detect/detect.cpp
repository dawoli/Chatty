#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,m,L,V,lp[N],rp[N],p[N];
struct Seg {
	int l,r;
	bool operator < (const Seg& b) const {
		return r<b.r;
	}
} s[N];
int flr(int x,int y) {
	if (x%y) return x/y;
	else return x/y-1;
}
void work() {
	//init()
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for (int i=1;i<=n;i++) {
		int d,v,a;
		scanf("%d%d%d",&d,&v,&a);
		if (a==0) {
			if (v<=V) lp[i]=rp[i]=-1;
			else lp[i]=d, rp[i]=L;
		} else if (a>0) {
			if (v>V) lp[i]=d, rp[i]=L;
			else {
				int p=(V*V-v*v)/(2*a)+1;
				if (d+p>L) lp[i]=rp[i]=-1;
				else lp[i]=d+p, rp[i]=L;
			}
		} else {
			if (v<=V) lp[i]=rp[i]=-1;
			else {
				int p=flr(v*v-V*V,-2*a);
				if (d+p>L) lp[i]=d, rp[i]=L;
				else lp[i]=d, rp[i]=d+p;
			}
		}
		//printf("%d %d\n",lp[i],rp[i]);
	}
	for (int i=1;i<=m;i++) scanf("%d",&p[i]);
	int cnt1=n, cnt2=m, now=-1;
	for (int i=1;i<=n;i++) {
		int l=lower_bound(p+1,p+m+1,lp[i])-p;
		int r=upper_bound(p+1,p+m+1,rp[i])-p-1;
		if (l>r) l=r=-1, cnt1--;
		//printf("%d %d\n",l,r);
		s[i].l=l, s[i].r=r;
	}
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
		if (s[i].l>now)
			now=s[i].r, cnt2--;
	printf("%d %d\n",cnt1,cnt2);
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--) work();
	return 0;
}
