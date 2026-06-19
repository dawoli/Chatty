#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Car{int x,y;} c[N];
int t,n,m,l,xv,d[N],v[N],a[N],p[N],ct,ans;
bool cmp(Car &a,Car &b) {
	return (a.x==b.x)?(a.y<b.y):(a.x<b.x);
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d%d%d",&n,&m,&l,&xv),ct=0;
		for (int i=1; i<=n; i++)
			scanf("%d%d%d",d+i,v+i,a+i);
		for (int i=1; i<=m; i++)
			scanf("%d",p+i);
		for (int i=1; i<=n; i++) {
			int jp=lower_bound(p+1,p+m+1,d[i])-p;
			if (jp>m) continue;
			if (!a[i]) {
				if (v[i]>xv) c[++ct]={jp,m};
				continue;
			}
			double val=d[i]+(xv*xv-v[i]*v[i])/(2.*a[i]);
			int lp=lower_bound(p+1,p+m+1,val)-p;
			int up=upper_bound(p+1,p+m+1,val)-p;
			if (a[i]>0) {
				if (lp>m) continue;
				c[++ct]={lp,m};
			}else if (jp<up) c[++ct]={jp,up-1};
		}
		sort(c+1,c+ct+1,cmp),ans=0;
		for (int i=1,pos=0; i<=ct; i++) {
			if (c[i].y<pos) pos=c[i].y;
			else if (c[i].x>pos) ans++,pos=c[i].y;
		}
		printf("%d %d\n",ct,m-ans);
	}
	return 0;
}
