#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD =  998244353;
ll fx[505];
ll n, m, p[505];
char h[505];

void init() {
	fx[1] = 1;
	for (int i = 2; i <= n; i++) {
		fx[i] = (fx[i-1]*i)%MOD;
	}
	return ;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	init();
	cout << fx[n];
	return 0;
}
