#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int n,x,maxn=-1,ans,tot;
int a[N],r[N],att[N];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&x);
		maxn = max(maxn,x);
		r[x]++;
		att[x]++;
	}
	for (int i = 1; i <= maxn; i++) if (r[i]) a[++tot] = i;
	int s1 = 1, s2 = 2;
	while (s1 <= tot && s2 <= tot)
		if (att[a[s2]] < r[a[s1]]) {
			r[a[s1]] -= att[a[s2]];
			att[a[s2]] = 0;
			s2++;
		} else if (att[a[s2]] > r[a[s1]]) {
			att[a[s2]] -= r[a[s1]];
			r[a[s1]] = 0;
			s1++;
			if (s1 == s2) s2++;
		} else {
			att[a[s2]] = r[a[s1]] = 0;
			s1++;
			s2++;
			if (s1 == s2) s2++;
		}
	for (int i = 1; i <= tot; i++) ans += r[a[i]];
	printf("%d\n",ans);
	return 0;
}
