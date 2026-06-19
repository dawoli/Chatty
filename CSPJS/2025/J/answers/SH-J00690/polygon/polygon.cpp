// polygon

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mbegin;

const int N = 5e3 + 10, MOD = 998244353;
int gA[N], gF[N][N];

bool mend;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int mxn = 0;
	for (int i = 1; i <= n; i++)
		cin >> gA[i], mxn = max(mxn, gA[i]);
	
	sort(gA + 1, gA + n + 1);
	
	int lim = mxn + 2; gF[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= lim; j++) {
			gF[i][j] = (gF[i][j] + gF[i - 1][j]) % MOD;
			gF[i][min(lim, j + gA[i])] = (gF[i][min(lim, j + gA[i])] + gF[i - 1][j]) % MOD;
		} 
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = gA[i] + 1; j <= lim; j++)
			sum = (sum + gF[i - 1][j]) % MOD;
		
		ans = (ans + sum) % MOD;
	} cout << ans << endl;
	
	// cerr << (&mend - &mbegin) / 1048576.0 << endl;
	return 0;
}
