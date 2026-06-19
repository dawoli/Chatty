#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][3],ct[3][N],los[N],ans;
bool cmp(const int &x,const int &y) {
	return los[x]<los[y];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n),ct[0][0]=ct[1][0]=ct[2][0]=ans=0;
		for (int i=1; i<=n; i++) {
			scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
			int mx=max({a[i][0],a[i][1],a[i][2]});
			int mi=min({a[i][0],a[i][1],a[i][2]});
			los[i]=mx-(a[i][0]+a[i][1]+a[i][2]-mx-mi),ans+=mx;
			if (mx==a[i][0]) ct[0][++ct[0][0]]=i;
			else if (mx==a[i][1]) ct[1][++ct[1][0]]=i;
			else ct[2][++ct[2][0]]=i;
		}
		for (int i=0; i<3; i++) {
			if (ct[i][0]<=n/2) continue;
			sort(ct[i]+1,ct[i]+ct[i][0]+1,cmp);
			for (int j=1; j<=(ct[i][0]-n/2); j++)
				ans-=los[ct[i][j]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
