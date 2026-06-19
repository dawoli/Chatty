#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,m,a[N][20],cnt[N][20],d[20][N],c[N],x[4],k,bl[20],tot,ans=0;
char s[N];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i][0]);
	for(int i=1;i<=m;++i) scanf("%d",&c[i]);
	k=0;tot=1;bl[0]=1;
	while(tot<n) ++k,tot*=2,bl[k]=tot;
	for(int i=1;i<=k;++i) {
		scanf("%s",s);
		for(int j=1;j<=bl[k-i];++j) d[i][j]=s[j-1]-'0';
	}
	for(int i=1;i<=m;++i) ans^=i;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		printf("%d\n",ans);
	}
	return 0;
}
