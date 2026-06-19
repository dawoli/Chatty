#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MX = 1e5 + 100, MXL = 1e6 + 100;
ll n, m, L, V, ansExceed, p[MX], sump[MXL];

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
struct Real {
	ll up, down;
	Real(): up(0), down(1) {}
	Real(ll _up, ll _down): up(_up), down(_down) {
		if (!down) {
			up = 0, down = 1;
			return;
		}
		if (down < 0) {
			up = -up;
			down = -down;
		}
		ll d = gcd(abs(up), abs(down));
		up /= d;
		down /= d;
	}
	Real(ll x) : up(x), down(1) {}
	Real ceil() {
		return Real(up / down + (up % down != 0), 1);
	}
	Real floor() {
		return Real(up / down, 1);
	}
	Real round() {
		return Real(up / down + (up % down * 2 >= down), 1);
	}
	ll to_ll() {
		return up / down;
	}
};
bool operator< (Real a, Real b) {
	return a.up * b.down < a.down * b.up;
}
bool operator> (Real a, Real b) {
	return b < a;
}
bool operator<= (Real a, Real b) {
	return !(a > b);
}
bool operator>= (Real a, Real b) {
	return !(a < b);
}
bool operator== (Real a, Real b) {
	return a <= b && a >= b;
}
bool operator!= (Real a, Real b) {
	return a < b || a > b;
}
Real operator+ (Real a, Real b) {
	return Real(a.up * b.down + b.up * a.down, a.down * b.down);
}
Real operator- (Real a, Real b) {
	return Real(a.up * b.down - b.up * a.down, a.down * b.down);
}
Real operator* (Real a, Real b) {
	return Real(a.up * b.up, a.down * b.down);
}
Real operator/ (Real a, Real b) {
	if (b == Real(0, 1)) return Real(0, 1);
	return Real(a.up * b.down, a.down * b.up);
}
ostream& operator<< (ostream& os, Real r) {
	os << r.up;
	if (r.down != 1) os << '/' << r.down;
	return os;
}
struct Car {
	Real d, v, a, l, r;
	ll exceed;
	Car(): d(0), v(0), a(0), exceed(0) {}
	Car(ll _d, ll _v, ll _a): d(_d), v(_v), a(_a), exceed(0) {}
	void calcVExceed() {
		if (a == 0) {
			if (v > V) {
				l = d, r = L;
				return;
			}
			l = r = -1;
			return;
		}
		Real dltX = (V * V - v * v) / 2 / a;
		if (dltX < 0) {
			if (a < 0) {
				l = r = -1;
				return;
			}
			l = d, r = L;
			return;
		}
		if (a > 0) {
			l = (d + dltX).floor() + 1, r = L;
			if (l > r) l = r = -1;
			return;
		}
		l = d, r = min((d + dltX).ceil() - 1, Real(L));
	}
	bool canBeDetected() {
		return l != -1 && r != -1 && sump[r.to_ll()] - sump[l.to_ll() - 1] > 0;
	}
} car[MX];

bool operator< (Car a, Car b) {
	return a.l != b.l ? a.l < b.l : a.r < b.r;
}
//
//bool check(ll k) {
//	ll used = 0;
//	memset(dp, 0, sizeof 0);
//	for (ll i = 1; i <= m; ++i) {
//		for (ll x = 0; x
//		for (ll j = dp[i - 1]
//	}
//}

void init() {
	n = m = L = V = ansExceed = 0;
	memset(p, 0, sizeof p);
	memset(sump, 0, sizeof sump);
	memset(car, 0, sizeof car);
}

void solve() {
	init();
	
	cin >> n >> m >> L >> V;
	for (ll i = 1; i <= n; ++i) {
		ll d, v, a;
		cin >> d >> v >> a;
		car[i] = {d, v, a};
		car[i].calcVExceed();
	}
	for (ll i = 1; i <= m; ++i) {
		cin >> p[i];
		++sump[p[i]];
	}
	for (ll i = 1; i <= L + 1; ++i) {
		sump[i] += sump[i - 1];
	}
	for (ll i = 1; i <= n; ++i) {
		car[i].exceed = car[i].canBeDetected();
		if (car[i].exceed) {
			++ansExceed;
		}
	}
	cout << ansExceed << ' ' << m - (ansExceed > 0) << '\n';
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;
	while (T--) solve();

	return 0;
}

