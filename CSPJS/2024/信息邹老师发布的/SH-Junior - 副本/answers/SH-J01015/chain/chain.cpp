#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int T;
int n, k, q;
int l[100005];
vector<int> s[100005];
int r, c;
bool flag;

bool equal(vector<int> a, vector<int> b) {
	if (a.size() != b.size()) return false;
	int len = a.size();
	for (int i = 0; i < len; i++)
		if (a[i] != b[i]) return false;
	return true;
}

bool check(int i, int j) {
	for (int x = 0; x < s[i].size(); x++) {
		if (s[i][x] == r) {
			vector<int> v1;
			for (int p1 = x, cnt1 = 1; p1 < s[i].size() && cnt1 <= k; p1++, cnt1++){
				v1.push_back(s[i][p1]);
				if (cnt1 == 1) continue;
				for (int y = 0; y < s[j].size(); y++) {
					if (s[i][p1] == s[j][y]) {
						vector<int> v2;
						for (int p2 = y, cnt2 = 1; p2 >= 0 && cnt2 <= k; p1++, cnt2--) {
							v2.push_front(s[j][p2]);
							if (equal(v1, v2)) continue;
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n >> k >> q;
		for (int i = 1; i <= n; i++) {
			s[i].clear();
			cin >> l[i];
			for (int j = 1; j <= l[i]; j++) {
				int x;
				cin >> x;
				s[i].push_back(x);
			}
		}
		while (q--) {
			cin >> r >> c;
			if (r == 1) {
				bool flag = false;
				for (int i = 1; i <= n && !flag; i++) {
					for (int j = 1; j <= n && !flag; j++) {
						if (i == j) continue;
						if (check(i, j) == false) flag = true;
					}
				}
				cout << (int)flag << endl;
			}
		}
	}

	return 0;
}
