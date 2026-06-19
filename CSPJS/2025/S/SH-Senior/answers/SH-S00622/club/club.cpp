#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

int min(int a, int b, int c) {
	return min(a, min(b, c));
}

struct Man{
	int d[3];
	bool operator < (const Man &m) const {
		int d2[3];
		int d2m[3];
		
		for (int i = 0; i < 3; i++) {
			d2[i] = d[i];
			d2m[i] = m.d[i];
		}
		
		sort(d2, d2 + 3);
		sort(d2m, d2m + 3);
		
		int p = d2[2] - d2[1];
		int pm = d2m[2] - d2m[1];
		return p > pm;
	}
};

priority_queue<Man> v[4];

void init() {
	while (!v[0].empty()) v[0].pop();
	while (!v[1].empty()) v[1].pop();
	while (!v[2].empty()) v[2].pop();
}

void solve() {
	init();
	
	long long ans = 0;
	int n;
	cin >> n;
	for (int T = 0; T < n; T++) {
		Man mc;
		cin >> mc.d[0] >> mc.d[1] >> mc.d[2];
		
		int bst = 0;
		for (int i = 0; i < 3; i++) {
			if (mc.d[i] > mc.d[bst]) bst = i;
		}
		
		int bnf[3] = {};
		for (int i = 0; i < 3; i++) {
			if (v[i].size() < n / 2) {
				bnf[i] = mc.d[i];
			} else {
				int j = (i + 1) % 3;
				int k = (i + 2) % 3;
				
				Man m = v[i].top();
				bnf[i] -= m.d[i];
				bnf[i] += max(m.d[j], m.d[k]);
				bnf[i] += mc.d[i];
			}
		}
		
		bst = 0;
		for (int i = 0; i < 3; i++) {
			if (bnf[bst] < bnf[i]) {
				bst = i;
			}
		}
		
		if (v[bst].size() < n / 2) {
			v[bst].push(mc);
			ans += mc.d[bst];
		} else {
			Man m = v[bst].top();
			v[bst].pop();
			
			int j = (bst + 1) % 3;
			int k = (bst + 2) % 3;
			
			if (m.d[j] > m.d[k]) {
				v[j].push(m);
				ans += m.d[j];
			} else {
				v[k].push(m);
				ans += m.d[k];
			}
			ans -= m.d[bst];
			
			v[bst].push(mc);
			ans += mc.d[bst];
		}
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		//cerr << t << endl;
		solve();
	}
	return 0;
}
