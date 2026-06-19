#include <bits/stdc++.h>
using namespace std;

const int N = 501;
const int M = 998244353;
int n,m,c[N],a[N],s[N];
char S[N];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,S+1);
	for (int i = 1; i <= n; i++) scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	
	for (int i = 1; i <= n; i++) a[i] = (S[i] == '0');
	
	s[1] = 0;
	for (int i = 2; i <= n; i++) s[i] = s[i-1]+a[i-1];
	
	int idx = upper_bound(c+1,c+n+1,s[n])-c;
	
	int pass = n-idx+1;
	if (pass >= m) {
		long long ans = 1;
		for (int i = 2; i <= n; i++) ans = ans*i%M;
		printf("%lld\n",ans);
	}
	return 0;
}
