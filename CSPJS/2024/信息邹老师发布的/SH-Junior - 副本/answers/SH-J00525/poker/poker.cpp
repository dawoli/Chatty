# include <iostream>
using namespace std;
int main() {
	int n, ans = 52;
	cin >> n;
	ans -= n;
	string a[53];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
