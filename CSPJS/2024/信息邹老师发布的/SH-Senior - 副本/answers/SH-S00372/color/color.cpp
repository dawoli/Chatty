#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int T,n,a[N];
namespace bf{
	const int N=20;
	int c[N];
	int color[N];
	ll ans;
	void getans(int cl) {
		for (int i=1;i<=n;++i) {
			color[i]=cl&1;
			cl>>=1;
		}
		for (int i=1;i<=n;++i) {
			c[i]=0;
			for (int j=i-1;j>=1;--j) {
				if (color[j]!=color[i]) continue;
				if (a[i]==a[j]) c[i]=a[i];
				break;
			}
		}	
		ll res=0;
		for (int i=1;i<=n;++i) {
			res+=c[i];
		}
		ans=max(ans,res);
	}
	void solve() {
		ans=0;
		for (int i=0;i<(1<<n);++i) {
			getans(i);
		}
		printf("%lld\n",ans);
	}
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;++i) {
			scanf("%d",&a[i]);
		}
		bf::solve();
	}
	return 0;
}

