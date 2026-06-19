#include <bits/stdc++.h>
using namespace std;
const int maxn=100009;
const double eps=1e-5;
int T,n,m,L,V,p[maxn],cnt[maxn];
bool overspeed[maxn];
vector<int> e[maxn]; 
struct car {
	int l,r;
} c[maxn];
bool cmp(car a,car b) {
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}
int ans1,ans2;
void init() {
	ans1=0; ans2=0;
	for(int i=1; i<=n; i++) c[i].l=0,c[i].r=0;
	for(int i=1; i<=n; i++) overspeed[i]=false;
	for(int i=1; i<=m; i++) e[i].clear();
	for(int i=1; i<=n; i++) cnt[i]=0;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&n,&m,&L,&V);
		init();
		for(int i=1,d,v,a; i<=n; i++) {
			scanf("%d%d%d",&d,&v,&a);
			if(a==0) {
				if(v<=V) { c[i].l=-1; c[i].r=-1;}
				else { c[i].l=d; c[i].r=L;}
			} else if(a>0) {
				if(v>V) { c[i].l=d; c[i].r=L;}
				else { double tmp=1.0*(V*V-v*v)/2/a; c[i].l=(int)tmp+1+d; c[i].r=L;}
			} else {
				if(v<=V) { c[i].l=-1; c[i].r=-1;} 
				else { c[i].l=d; double tmp=1.0*(V*V-v*v)/2/a; if(tmp-(int)tmp>eps) c[i].r=(int)tmp+d; else c[i].r=(int)tmp-1+d;}
			}
		}
		sort(c+1,c+1+n,cmp);
		for(int i=1; i<=m; i++) scanf("%d",&p[i]);
		int tmp=1;
		for(int i=1; i<=n; i++) {
			if(c[i].l==-1) continue;
			for(int j=tmp; j<=m; j++) {
				if(c[i].r<p[j]) break;
				if(c[i].l<=p[j] && c[i].r>=p[j]) {
					overspeed[i]=true;
					e[j].push_back(i);
				}
				if(c[i].l>p[j]) tmp++;
			}
		}
		for(int i=1; i<=n; i++) if(overspeed[i]) ans1++;
		for(int i=1; i<=m; i++)
			for(int j=0; j<e[i].size(); j++) cnt[e[i][j]]++;
		for(int i=1; i<=m; i++) {
			bool flag=true;
			for(int j=0; j<e[i].size(); j++) {
				if(cnt[e[i][j]]==1) {
					flag=false;
					break;
				}
			}
			if(flag) {
				for(int j=0; j<e[i].size(); j++) cnt[e[i][j]]--;
				ans2++;
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}

