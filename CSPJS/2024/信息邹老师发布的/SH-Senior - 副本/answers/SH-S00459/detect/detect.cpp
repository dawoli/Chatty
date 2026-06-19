#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100010,maxl=1000010;
int T,n,m,l,V,ans1,ans2;
int p[maxn],r[maxl],aa[maxl],bb[maxn];
struct car {
	int d,v,a;
} c[maxn];
bool cmp(car A,car B) {
	return A.d<B.d;
}
struct spt {
	int pos,wei;
} d[maxn];
bool cmp2(spt A,spt B) {
	return A.wei<B.wei; 
} 
bool overspeed(int cur) {
	const int a=c[cur].a,v=c[cur].v,d=c[cur].d;
	if (a==0||a<0) {
		if (v>V) return true;
		return false;
	}
	if (sqrt((ll)(v*v+2ll*(ll)a*(ll)l))<=V) return false;
	return true;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		bool isallzero=1;
		scanf("%d%d%d%d",&n,&m,&l,&V);
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
			if (c[i].a<0) isallzero=0; 
		}
		for (int i=1;i<=m;i++) {
			scanf("%d",&p[i]);
		}
		//sort(p+1,p+1+m); sort(c+1,c+1+n,cmp);
		int j=1; r[0]=0; ans1=0; ans2=0;
		for (int i=1;i<=l,j<=m;i++) {
			r[i]=p[j];
			if (i>=p[j]) {
				do{j++;}while(p[j]<=i&&j<=m);
			}
		}
		//for (int i=1;i<=l;i++) printf("%d ",r[i]); puts("");
		for (int i=1;i<=n;i++) {
			if (overspeed(i)) {
			    if (c[i].a==0) {
			    	if (r[c[i].d]!=0) {
					    ans1++;
					    aa[c[i].d]++; aa[p[m]+1]--;
					    //printf("i=%d %d=>%d\n",i,c[i].d,p[m]);
					}
				} else {
					int sp,spl;
					if (c[i].a>0) {
					    sp=c[i].v*c[i].v+2*c[i].a*(p[m]-c[i].d);
					    if (sp>V*V) {
					        ans1++;
					        spl=floor((V*V-c[i].v*c[i].v)*1.0/(2.0*c[i].a))+1;
					        aa[c[i].d+spl]++; aa[p[m]+1]--;
					        //printf("i=%d %d=>%d\n",i,c[i].d+spl,p[m]);
					    }
					} else {
						sp=c[i].v*c[i].v+2*c[i].a*(r[c[i].d]-c[i].d);
						if (sp>V*V) {
					        ans1++;
					        spl=ceil((V*V-c[i].v*c[i].v)*1.0/(2.0*c[i].a))-1;
					        aa[r[c[i].d]]++; aa[c[i].d+spl]--;
					        //printf("i=%d %d=>%d\n",i,r[c[i].d],c[i].d+spl);
					    }
					}
				} 
			}
		}
		if (isallzero) {printf("%d 1\n",ans1);continue;}
		for (int i=1;i<=l;i++) {
			bb[i]=bb[i-1]+aa[i];
		}
		//for (int i=1;i<=l;i++) printf("%d ",aa[i]); puts("");
		//for (int i=1;i<=l;i++) printf("%d ",bb[i]); puts("");
		for (int i=1;i<=m;i++) {
			d[i].pos=p[i]; d[i].wei=bb[p[i]];
		}
		sort(d+1,d+1+m,cmp2);
		for (int i=1;i<=m;i++) {
			if (d[i].wei<d[m].wei) {
				ans2++;
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
