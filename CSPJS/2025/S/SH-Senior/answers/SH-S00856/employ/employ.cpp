#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MOD = 998244353, MAXN = 505;
int n,m,a[MAXN],kk;
string di;
unsigned int jiecheng(int x) {
	if(x == 0) return 0;
	unsigned int res = 1;
	for(int i = 2;i <= x;i ++) res = res * x % MOD;
	return res;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> di;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(a[i]==0) kk++;
	}
	// Ãÿ ‚–‘÷ A
	cout << jiecheng(n-kk) << '\n';
	return 0;
}
