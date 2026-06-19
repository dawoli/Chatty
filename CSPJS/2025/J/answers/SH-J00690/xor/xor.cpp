// xor

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 10;
int gA[N], gSum[N], gPre[N], gF[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> gA[i], gSum[i] = (gSum[i - 1] ^ gA[i]);
	
	memset(gPre, -1, sizeof(gPre)); gPre[0] = 0;
	for (int i = 1; i <= n; i++) {
		int id = gPre[gSum[i] ^ k]; gF[i] = gF[i - 1];
		if (id >= 0) gF[i] = max(gF[i], gF[id] + 1);
		gPre[gSum[i]] = i;
	}
	
	int mx = 0;
	for (int i = 0; i <= n; i++)
		mx = max(mx, gF[i]);
	
	cout << mx << endl;
	return 0;
}
