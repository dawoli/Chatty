#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N = 505;
const long long mod = 998244353;
long long jc[N];
int n,m;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0] = 1;
	for(int i = 1;i <= 500;i++) {
		jc[i] = jc[i - 1] * i % mod;
	}
	scanf("%d%d",&n,&m);
	printf("%lld\n",jc[n]);
	fclose(stdin),fclose(stdout);
	return 0;
}
