#include <bits/stdc++.h> 
using namespace std;
int k, n, m, pos;
int a[105];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) cin >> a[i];
	k = a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++) {
		if(a[i] == k) {
			pos = i;
			break;
		}
	}
	int c = (pos+n-1)/n;
	if(pos % (2*n) > n) cout << c << ' ' << n-pos%n+1;
	else if(pos % (2*n) == 0) cout << c << ' ' << 1;
	else if(pos % (2*n) == n) cout << c << ' ' << n;
	else cout << c << ' ' << pos%n;
	return 0;
}
