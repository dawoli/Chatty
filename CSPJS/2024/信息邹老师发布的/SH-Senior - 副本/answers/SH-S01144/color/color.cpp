#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],ans;
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n),ans=0;
		for (int i=1; i<=n; i++)
			scanf("%d",a+i);
		for (int i=0; i<(1<<n); i++) {
			int sec=0;
			for (int j=0,x=-1,y=-1; j<n; j++) {
				if (i&(1<<j)) {
					if (x==a[j+1]) sec+=x;
					x=a[j+1];
				}else {
					if (y==a[j+1]) sec+=y;
					y=a[j+1];
				}
			}
			ans=max(ans,sec);
		}
		printf("%d\n",ans);
	}
	return 0;
}
