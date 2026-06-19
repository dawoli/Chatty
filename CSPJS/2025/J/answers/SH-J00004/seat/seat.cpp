#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a, int b) {return a > b;}
const int N = 1010;
int m, n, a[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	for(int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int me = a[1], now;
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= m * n; i++) {
		if(a[i] == me) {
			now = i;
			break;
		}
	}
	if(now % m == 0) {
		if(now / m % 2 == 0) cout << now / m <<' ' << 1;
		else cout << now / m << ' ' << n;
		return 0;
	}
	if((now / m + 1) % 2 == 0) {
		if(n - now % n + 1 > n) cout << now / m + 1 << ' ' << n ; 
		else cout << now / m + 1 << ' ' << n - now % n + 1 ; 
	} else {
		cout << now / m + 1 << ' ' << now % m == 0 ? m : now % m;
	}
	return 0;
} 
