#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n;
int r[N];

int cnt = 0;
int cur = 0;

int main() {
	freopen("duel.in", "r", stdin) ;
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
	}
	sort(r + 1, r + 1 + n);
	for (int i = 1; i <= n; i++) {
		if (r[i - 1] != r[i]) {
			cnt += cur;
			cur = 0;
		}
		if (cnt) cnt--;
		cur++;
	}
	cnt += cur;
	cout << cnt;
}
