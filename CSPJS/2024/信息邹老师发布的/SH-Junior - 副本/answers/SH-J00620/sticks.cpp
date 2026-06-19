// sticks

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int gF[N];
PII gG[N];
 
signed main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int fgx[10] = {0};
	fgx[2] = 1; fgx[3] = 7; fgx[4] = 4; fgx[5] = 2; fgx[6] = 0, fgx[7] = 8;
	
	for (int i = 0; i < N; i++)
		gG[i].second = INF;
	
	memset(gF, 0x3f, sizeof(gF)); gF[0] = 0; gG[1].second = -1;
	for (int i = 2; i < N; i++) 
		for (int j = 2; j <= min(7LL, i); j++) {
			int tmp = gF[i - j] + 1;
			if (gF[i] > tmp || (gF[i] == tmp && gG[i].second > fgx[j])) 
				gF[i] = tmp, gG[i] = make_pair(i - j, fgx[j]);
		}
	
//	cout << "check st:\n";
//	cout << gF[5] << endl;
//	cout << gF[13] << endl;
//	cout << gF[18] << endl;
//	cout << "check en:\n";
//	
//	for (int i = 1; i <= 20; i++)
//		cout << i << "->" << gG[i].first << " " << gG[i].second << endl;
	
	int t;
	cin >> t;
	
	fgx[6] = 6;
	while (t--) {
		int n;
		cin >> n;
		
		if (n == 1) {
			cout << "-1\n";
			continue;
		} 
		
		int ans = INF, lst = INF, mxn = n;
		for (int i = 2; i <= min(7LL, n); i++) {
			int tmp = gF[n - i] + 1; // cout << "chs:" << tmp << " " << fgx[i] << "<-" << tmp << " " << ans << endl; 
			if (tmp < ans || (tmp == ans && lst > fgx[i])) ans = tmp, lst = fgx[i], mxn = n - i; // BUGBUG ”≈œ»º∂ 
		}
		
		// cout << "lst=" << lst << endl;
		int now = mxn; string s; s += (lst + '0');
		while (now) {
			s += (gG[now].second + '0');
			now = gG[now].first;
		} cout << s << endl;
	}
	
	return 0; 
}
