#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, r[100001];
bool if_los[100001], if_att[100001];
ll maxr;

bool if_fi() {
	ll ave = 0, ffx = 0;
	bool if_a = 0;
	for (ll i = 1; i <= n; i++) {
		if (if_los[i] == 0 && if_att[i] == 0) {
			ave = r[i];
			ffx = i+1;
			break;
		}
	}
	if (ave == 0) return 0;
	for (ll i = 1; i <= n; i++) {
		if (r[i] != ave) return 1;
	}
	return 0;
}


int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> r[i];
	}
	sort(r+1, r+n+1);
	
	ll win = 0, los = 0, fx = 1;
	while (if_fi()) {
		while (los == 0) {
			if (if_los[fx] == 0 && fx != 0) {
				los = fx;
				break;
			}
			fx++;
			if (fx > n) {
				break;
			}
		}
		while (win == 0) {
			if (if_los[fx] == 0 && if_att[fx] == 0 && r[fx] > r[los] && fx != 0) {
				win = fx;
				break;
			}
			fx++;
			if (fx > n) {
				break;
			}
		}
		if (win == 0 || los == 0) break;
		//cout << win << " ko " << los << endl;
		if_los[los] = 1; if_att[win] = 1;
		fx = 1; los = win = 0;
	}
	
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (if_los[i] == 0) cnt++;
	}
	cout << cnt;
	return 0;
}
