#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t;
int n;
struct NODE{
	int a,b,c;
}q[100010];
int a[100010][4];
int f[100010][4];
int g[100010][4][4];
bool cmp(NODE a,NODE b) {
	if(a.a!=b.a)return a.a>b.a;
	if(a.b!=b.b)return a.b>b.b;
	return a.c>b.c;
}
signed main(){
	freopen("club5.in","r",stdin);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&q[i].a,&q[i].b,&q[i].c);
//			for(int j=1;j<=3;j++){
//				scanf("%lld",&a[i][j]);
//			}
		}
		sort(q+1,q+n+1,cmp);
		for(int i=1;i<=n;i++){
			a[i][1]=q[i].a;
			a[i][2]=q[i].b;
			a[i][3]=q[i].c;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int mx=0,mxk;
				for(int k=1;k<=3;k++){
					if(g[i-1][k][j]<n/2){
						if(mx<f[i-1][k]){
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
	return 0;
}
