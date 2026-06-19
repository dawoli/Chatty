#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

int n, m;
int K;
uint a_cal[114514];
uint a[114514];
int c[114514];
char d[451411];

int ghost(int r, int g) {
	int k = (1 << r);
	return k + g;
}

int log2(int num) {
	int cnt = 0;
	
	do {
		cnt++;
	} while (num >> 1);
	
	return cnt;
}

bool prob[800005];
int known[800005];

void init() {
	for (int i = 0; i < 2 * n + 100; i++) {
		prob[i] = false;
		known[i] = 0;
	}
	int x[4];
	cin >> x[0] >> x[1] >> x[2] >> x[3];
	
	for (int i = 0; i < n; i++) {
		a[i] = a_cal[i] ^ x[i % 4];
	}
}


void solve(int cnt, int r, int g) {
	int hid = ghost(r, g);
	if (r == 0) {
		if (g < cnt)
			known[hid] = a[g];
		else
			known[hid] = -1;
		return;
	}
	int host = d[hid];
	
	solve(cnt, r - 1, g * 2);
	solve(cnt, r - 1, g * 2 + 1);
	
	if (host == 0) {
		if (known[hid * 2] != -1) {
			if (known[hid * 2 + 1] > r) {
				known[hid] = known[hid * 2];
				prob[hid * 2] = true;
			} else {
				known[hid] = known[hid * 2 + 1];
				prob[hid * 2 + 1] = true;
			}
		} else {
			prob[hid * 2] = true;
			prob[hid * 2 + 1] = true;
		}
	} else {
		if (known[hid * 2 + 1] != -1) {
			if (known[hid * 2 + 1] > r) {
				known[hid] = known[hid * 2];
				prob[hid * 2] = true;
			} else {
				known[hid] = known[hid * 2 + 1];
				prob[hid * 2 + 1] = true;
			}
		} else {
			prob[hid * 2] = true;
			prob[hid * 2 + 1] = true;
		}
	}
}

int output(int cnt, int root = 0) {
	int k = cnt;
	bool f = false;
	while (k & (k - 1) != 0) {
		k &= k - 1;
		f = true;
	}
	if (f) k <<= 1;
	
	if (root > k) {
		return root - k;
	}
	
	int sum = 0;
	
	if (prob[root * 2]) sum += output(root * 2);
	if (prob[root * 2 + 1]) sum += output(root * 2 + 1);
	
	return sum;
}

int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int T;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a_cal[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}
	
	K = n;
	bool f = false;
	while (K & (K - 1) != 0) {
		K &= K - 1;
		f = true;
	}
	if (f) K <<= 1;
	
	int temp = K << 2;
	
	for (int i = 0; i < log2(K); i++) {
		for (int j = temp; j < (K >> i); j++) {
			cin >> d[j];
		}
		temp <<= 2;
	}
	
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		int res = 0;
		for (int i = 0; i < m; i++) {
			solve(c[i], log2(K - 1), 0);
			res ^= (i + 1) * output(c[i]);
		}
	}
}
