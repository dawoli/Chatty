#include <bits/stdc++.h>
using namespace std;
bool d[14], c[14], h[14], s[14];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		string t; cin >> t;
		if (t[0] == 'D'){
			if (t[1] - '0' > 1 && t[1] - '0' <= 9) d[t[1] - '0'] = 1;
			else if (t[1] == 'A') d[1] = 1;
			else if (t[1] == 'T') d[10] = 1;
			else if (t[1] == 'J') d[11] = 1;
			else if (t[1] == 'Q') d[12] = 1;
			else if (t[1] == 'K') d[13] = 1;
		} else if (t[0] == 'C'){
			if (t[1] - '0' > 1 && t[1] - '0' <= 9) c[t[1] - '0'] = 1;
			else if (t[1] == 'A') c[1] = 1;
			else if (t[1] == 'T') c[10] = 1;
			else if (t[1] == 'J') c[11] = 1;
			else if (t[1] == 'Q') c[12] = 1;
			else if (t[1] == 'K') c[13] = 1;
		} else if (t[0] == 'H'){
			if (t[1] - '0' > 1 && t[1] - '0' <= 9) h[t[1] - '0'] = 1;
			else if (t[1] == 'A') h[1] = 1;
			else if (t[1] == 'T') h[10] = 1;
			else if (t[1] == 'J') h[11] = 1;
			else if (t[1] == 'Q') h[12] = 1;
			else if (t[1] == 'K') h[13] = 1;
		} else if (t[0] == 'S'){
			if (t[1] - '0' > 1 && t[1] - '0' <= 9) s[t[1] - '0'] = 1;
			else if (t[1] == 'A') s[1] = 1;
			else if (t[1] == 'T') s[10] = 1;
			else if (t[1] == 'J') s[11] = 1;
			else if (t[1] == 'Q') s[12] = 1;
			else if (t[1] == 'K') s[13] = 1;
		}
	} int ans = 0;
	for (int i = 1; i <= 13; i++) if (!d[i]) ans++;
	for (int i = 1; i <= 13; i++) if (!c[i]) ans++;
	for (int i = 1; i <= 13; i++) if (!h[i]) ans++;
	for (int i = 1; i <= 13; i++) if (!s[i]) ans++;
	cout << ans << endl;
	return 0;
}
