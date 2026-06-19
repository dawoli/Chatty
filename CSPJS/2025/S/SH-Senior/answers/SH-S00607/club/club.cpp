#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
struct NODE {
	int a,b,c;
} q[100010];
int a[100010][4];
int f[100010][4];
int g[100010][4][4];
bool cmp(NODE a,NODE b) {
	if(a.a!=b.a)return a.a>b.a;
	if(a.b!=b.b)return a.b>b.b;
	return a.c>b.c;
}
int ans=0,cnt=0;
void dfs(int depth=1,int ca=0,int cb=0,int cc=0) {
	if(depth>n) {
		ans=max(ans,cnt);
		return;
	}
	if(ca<n/2) {
		cnt+=a[depth][1];
		dfs(depth+1,ca+1,cb,cc);
		cnt-=a[depth][1];
	}
	if(cb<n/2) {
		cnt+=a[depth][2];
		dfs(depth+1,ca,cb+1,cc);
		cnt-=a[depth][2];
	}
	if(cc<n/2) {
		cnt+=a[depth][3];
		dfs(depth+1,ca,cb,cc+1);
		cnt-=a[depth][3];
	}
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) {
		scanf("%lld",&n);
		if(n<100000) {
			for(int i=1; i<=n; i++) {
				scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			}
			dfs();
			printf("%lld\n",ans);
			ans=0;
			continue;
		}
		else {
			for(int i=1; i<=n; i++) {
				scanf("%lld%lld%lld",&q[i].a,&q[i].b,&q[i].c);
			}
			sort(q+1,q+n+1,cmp);
			for(int i=1; i<=n; i++) {
				a[i][1]=q[i].a;
				a[i][2]=q[i].b;
				a[i][3]=q[i].c;
			}
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=3; j++) {
					int mx=0,mxk;
					for(int k=1; k<=3; k++) {
						if(g[i-1][k][j]<(n/2)) {
							if(mx<f[i-1][k]) {
								mx=f[i-1][k];
								mxk=k;
							}
						}
					}
					f[i][j]=mx+a[i][j];
					g[i][j][1]=g[i-1][mxk][1];
					g[i][j][2]=g[i-1][mxk][2];
					g[i][j][3]=g[i-1][mxk][3];
					g[i][j][j]++;
				}
			}
			printf("%lld\n",max(f[n][1],max(f[n][2],f[n][3])));
			memset(f,0,sizeof(f));
			memset(g,0,sizeof(g));
		}
	}
	return 0;
}
//I think I have leave from OI.
//I am grade 9 now.
//This is the last time I attend CSP when I am in middle school.
//Hope for a good score.
//---from No4 middle school affiliated to ECNU 
//--Chang__An__Li
