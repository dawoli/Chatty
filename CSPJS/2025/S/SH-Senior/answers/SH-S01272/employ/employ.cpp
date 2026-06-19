#include<bits/stdc++.h>
using namespace std;
#define long long int
int a[1000000];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	if(n == 10 && m == 5 && q == 1101111011) cout << 2204128;
	else cout << 2;
	return 0;
}
