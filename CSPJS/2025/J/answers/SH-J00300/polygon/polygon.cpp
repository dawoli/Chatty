#include <bits/stdc++.h>
using namespace std;

unsigned long long n, cnt = 0;
unsigned long long sticks[5005];
vector<long long> v;
void f (unsigned long long x) {
	if (x == n+1) {
		if (v.size() < 3) {
			return;
		}
		else {
			long long max_ = -1;
			unsigned long long sum_ = 0;
			for (unsigned long long i = 0; i < v.size(); i++) {
				max_ = max(max_, v[i]);
				sum_ += v[i];
			}
			if (sum_ > 2*max_) {
				cnt ++;
				cnt %= 998244353;
			}
		}
		return;
	}
	v.push_back(sticks[x]);
	f (x+1);
	v.pop_back();
	f (x+1);
}
unsigned long long fast_pow(int p, int x) {
	if (x == 0) return 1;
	if (x == 1) return (unsigned long long) p;
	if (x % 2 == 1) {
		unsigned long long t = fast_pow(p, x/2) % 998244353;
		return t * t * p % 998244353;
	}
	else {
		unsigned long long t = fast_pow(p, x/2) % 998244353;
		return t * t % 998244353;
	}
}

int main() {
	//60
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for (unsigned long long i = 1; i <= n; i++) {
		cin >> sticks[i];
		if (sticks[i] != 1) {
			flag = false;
		}
	}
	if (flag) {
		unsigned long long t = fast_pow(2, n) - 1 - n - n * (n-1) / 2;
		cout << t << endl;
	}
	else {
		f (1);
		cout << cnt << endl;
	}
	return 0;
}
