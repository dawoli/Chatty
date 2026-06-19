#include <bits/stdc++.h>
using namespace std;
const int N=2e5,LEN=2e6;
int T;
int n,m,L,V;
int ans;
int d[N],v[N],a[N];
int p[LEN],ps[LEN];
int ov[N][2],ovn,to[N];
void add(int l,int r) {
	int psl,psr;
	if(l==0) psl=0;
	else psl=ps[l-1];
	psr=ps[r];
	if(psl<psr) {
		ovn++;
		ov[ovn][0]=psl+1;
		ov[ovn][1]=psr;
	}
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		ans=0;
		memset(p,0,sizeof(p));
		memset(ps,0,sizeof(ps));
		ovn=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++) {
			int pos;
			scanf("%d",&pos);
			p[pos]++;
		}
		for(int i=0;i<=L;i++) {
			if(i==0) ps[i]=p[i];
			else ps[i]=ps[i-1]+p[i];
		}
		for(int i=1;i<=n;i++) {
			if(a[i]>0) {
				if(v[i]>V) {
					add(d[i],L);
				}
				else {
					int dm=d[i]+(V*V-v[i]*v[i])/(2*a[i])+1;
					if(dm<=L) {
						add(dm,L);
					}
				}
			} 
			else if(a[i]==0) {
				if(v[i]>V) {
					add(d[i],L);
				}
			}
			else {
				if(v[i]>V) {
					int dm=d[i]+(v[i]*v[i]-V*V-2*a[i]-1)/(-2*a[i])-1;
					add(d[i],min(dm,L));
				}
			}
		}
		for(int i=1;i<=m;i++) {
			to[i]=L+1;
		}
		for(int i=1;i<=ovn;i++) {
			to[ov[i][0]]=min(to[ov[i][0]],ov[i][1]);
		}
		int mn=L+1;
		for(int i=1;i<=m;i++) {
			if(to[i]!=L+1) {
				mn=min(mn,to[i]);
			}
			if(mn==i) {
				mn=L+1;
				ans++;
			}
		}
		printf("%d %d\n",ovn,m-ans);
	}
	return 0;
}

