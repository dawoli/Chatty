#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
	int l;
	int r;
};

int n;
long long k;
long long a[500010];
long long b[500010];
State s[60000000];
long long index;
vector<State> used;
long long ans;

bool CMP(State x, State y) {
	return (x.r == y.r ? x.l > y.l : x.r < y.r);
}

long long Xor(int l, int r) {
	return b[r] ^ b[l - 1];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	// n^2
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) 
			if (Xor(i, j) == k) s[++index] = { i, j };
	// nlogn
	sort(s + 1, s + index + 1, CMP);
	// n^4
	for (long long i = 1; i <= index; i++) {
		if (!used.empty())
			if (s[i].l <= used[used.size() - 1].r) continue;
		used.push_back(s[i]);
		ans++;
	}
	cout << ans << endl;
	return 0;
}
