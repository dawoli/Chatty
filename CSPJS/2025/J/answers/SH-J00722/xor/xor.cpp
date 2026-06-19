#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int le, ri, va;
};

const int mx = 5e5 + 9;
int n, k, ans, flag, a[mx], p[mx];
bool flagb = true;
vector<node> ve;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	cin >> a[1];
	if (a[1] == 1) {
		flag++;
	}
	if (a[1] != 0 && a[1] != 1) {
		flagb = false;
	}
	p[1] = a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			flag++;
		}
		if (a[i] != 0 && a[i] != 1) {
			flagb = false;
		}
		p[i] = p[i - 1] ^ a[i];
	}
	if (flag == n) {
		if (k == 0) {
			cout << n;
		} else if (k == 1) {
			cout << n / 3;
		} else {
			cout << 0;
		}
	} else if (flagb) {
		if (k != 0 && k != 1) {
			cout << 0;
		} else {
			for (int l = 1; l <= n; l++) {
		for (int r = n; r > 0; r--) {
			if (l > r) {
				continue;
			} else if (l == r) {
				if ((p[l] | p[l]) == k) {
					ve.push_back({l, r, r - l + 1});
				}
			} else {
				if ((p[r] | p[l - 1]) == k) {
					ve.push_back({l, r, r - l + 1});
				}
			}
		}
	}
	cout << ve.size();
		}
	} else {
	for (int l = 1; l <= n; l++) {
		for (int r = n; r > 0; r--) {
			if (l > r) {
				continue;
			} else if (l == r) {
				if ((p[l] | p[l]) == k) {
					ve.push_back({l, r, r - l + 1});
				}
			} else {
				if ((p[r] | p[l - 1]) == k) {
					ve.push_back({l, r, r - l + 1});
				}
			}
		}
	}
	cout << ve.size();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
