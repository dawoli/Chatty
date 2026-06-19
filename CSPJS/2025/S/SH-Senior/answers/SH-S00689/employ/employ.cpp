//// employ
//
//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//
//bool mbegin;
//
//const int N = 50 + 10, LIM = 5e6 + 10, MOD = 998244353;
//int gA[N], gFac[LIM], gP[N], gSum[N], gF[N][N][N][N];
//
//bool mend;
//
//signed main() {
//	ios::sync_with_stdio(false);
//	
//	gFac[0] = 1;
//	for (int i = 1; i < LIM; i++) gFac[i] = (gFac[i - 1] * i) % MOD;
//	
//	int n, m;
//	cin >> n >> m;
//	
//	string s;
//	cin >> s;
//	
//	s = " " + s;
//	for (int i = 1; i <= n; i++)
//		gA[i] = (s[i] - '0');
//	
//	for (int i = 1; i <= n; i++)
//		cin >> gP[i], gSum[gP[i]]++;
//	
//	for (int i = 1; i <= n; i++)
//		gSum[i] += gSum[i - 1];
//	
//	for (int i = 1; i <= n; i++)
//		cout << gSum[i] << " ";
//	cout << endl;
//	
//	gF[0][0][0][0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int a = 0; a <= i; a++)
//			for (int b = 0; b <= i - a; b++) 
//				for (int k = 0; k <= n; k++) {
//					int c = i - a - b, chk = ((i == b) ? 0 : gSum[i - b - 1]) % MOD;
//					if (a && s[i] == '0') gF[i][a][b][k] = (gF[i][a][b][k] + gF[i - 1][a - 1][b][k]) % MOD;
//					if (b && k && s[i] == '1') {
//						gF[i][a][b][k] = (gF[i][a][b][k] + k * gF[i - 1][a][b - 1][k - 1] % MOD) % MOD;
//						gF[i][a][b][k] = ((gF[i][a][b][k] - max(0LL, chk - c) * gF[i - 1][a][b][k]) % MOD + MOD) % MOD;
//					}
//					
//					if (s[i] == '1') 
//						gF[i][a][b][k] = (gF[i][a][b][k] + max(0LL, chk - c) * gF[i - 1][a][b][k] % MOD) % MOD;
//					
//					cout << i << " " << a << " " << b << " " << k << ":::" << gF[i][a][b][k] << "chk:" << chk << "-" << c << endl; 
//				}
//	}
//	
//	int ans = 0;
//	for (int a = 0; a <= n; a++)
//		for (int b = 0; b <= n - a; b++)
//			for (int k = 0; k <= n; k++) {
//				int c = n - a - b;
//				if (b >= m) {
//					if (gF[n][a][b][k]) cout << n << " " << a << " " << b << " " << k << ":" << gF[n][a][b][k] << "*" << gFac[a + k] << endl;
//					ans = (ans + gF[n][a][b][k] * gFac[a + k] % MOD) % MOD;
//				}
//			}
//	
//	cout << ans << endl;
//	
//	cerr << (&mbegin - &mend) / 1048576.0 << endl;
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e2 + 10, M = 20, K = (1LL << 18) + 10, MOD = 998244353;
int gA[N], gF[K][M], gC[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	s = " " + s;
	for (int i = 1; i <= n; i++)
		gA[i] = (s[i] - '0');
	
	for (int i = 1; i <= n; i++)
		cin >> gC[i];
	
	int mxn = (1LL << n); gF[0][0] = 1;
	for (int bit = 0; bit < mxn; bit++) {
		int pop = __builtin_popcount(bit) + 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n; j++) 
				if (!(bit & (1LL << i - 1))) {
					int nxt = j + (gC[i] <= j);
					if (gA[pop]) gF[bit | (1LL << i - 1)][nxt] = (gF[bit | (1LL << i - 1)][nxt] + gF[bit][j]) % MOD;
					else gF[bit | (1LL << i - 1)][j + 1] = (gF[bit | (1LL << i - 1)][j + 1] + gF[bit][j]) % MOD;
				}
	}
	
	int ans = 0;
	for (int i = 0; i <= n - m; i++)
		ans = (ans + gF[mxn - 1][i]) % MOD;
	
	cout << ans << endl;
	return 0;
}
