#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+1;
int T,n,ans;
int a[N];
signed main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while (T--) {
		scanf("%lld",&n);
		for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for (int i = 2; i <= n; i++)
			for (int j = i-1; j > 0; j--) if (a[i] == a[j]) {
				ans += a[i];
				break;
			}
		printf("%lld\n",ans);
		ans = 0;
	}
	return 0;
}
