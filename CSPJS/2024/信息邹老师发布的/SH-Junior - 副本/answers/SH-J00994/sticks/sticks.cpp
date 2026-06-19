#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n;
ll use[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll digits(ll m) {
	if(m == 1) return -1;
	ll x = m/7;
	if(m%7 != 0) x++;
	return x;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		if(n == 1) {
			cout << -1 << endl;
			continue;
		}
		// enumerate over first digit
		while(true) {
			ll mndgt = n, stt = 0;
			for(ll i = 1; i <= 9; i++) {
				ll nrm = n-use[i];
				ll dgt = digits(nrm);
				if(dgt == -1) continue;
				if(dgt < mndgt) mndgt = dgt, stt = i;
			}
			n -= use[stt];
			ll allzero = mndgt*6;
			ll rem = n-allzero;
			ll zeros = mndgt-rem;
			cout << stt;
			if(rem >= 0 && zeros >= 0) {
				for(ll i = 1; i <= zeros; i++) cout << 0;
				for(ll i = 1; i <= rem; i++) cout << 8;
				break;
			}
		}
		cout << endl;
	}
	return 0;
}

