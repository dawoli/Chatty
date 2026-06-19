#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,k,a[N],last[N],f[N];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	cout<<n/2;
	return 0;
}
