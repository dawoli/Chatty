#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000 + 10;
const int mod = 998244353;
int a[N], n, cnt;
bool cmp(int a, int b){return a > b;}
void check(int i) {
	int j = 1, sum = 0, ma = -1, c = 0;;
	while(i) {
		if(i & 1) {
			c++;
			sum += a[j];
			ma = max(ma, a[j]);
		}
		
		i >>= 1;
		j++;
		j %= mod;
	}
	if(sum > 2 * ma && c >= 3) cnt++;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= 1 << n; i++) {
		check(i);
	}
	cout << cnt;
	return 0;
}
