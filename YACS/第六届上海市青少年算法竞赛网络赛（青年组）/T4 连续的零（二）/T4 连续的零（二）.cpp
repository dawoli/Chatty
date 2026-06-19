#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int left = 0, cnt_ones = 0, max_len = 0;
	for (int right = 0; right < n; ++right) {
		if (s[right] == '1') {
			++cnt_ones;
		}
		while (cnt_ones > k) {
			if (s[left] == '1') {
				--cnt_ones;
			}
			++left;
		}
		max_len = max(max_len, right - left + 1);
	}
	cout << max_len  ;
	return 0;
}
