#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], ans;
string to2(int cur) {
	string str;
//	cout << cur << endl;
	while (cur > 0) {
		char temp = (cur % 2) + '0';
//		cout << "-----" << temp << '\n';
		cur /= 2;
		str = (temp + str);
	}
	int len = str.size();
	while (len < n) str = ('0' + str), len++;
	return str;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= (1 << n); i++) {
		string s = to2(i);
//		cout << s << endl;
		int sumstick = 0, len = s.size(), l = 0;
		for (int k = len - 1; k >= 0; k--) {
			if (s[k] == '1') {
				sumstick += a[k + 1];
				l = max(l, k + 1); 
			}
		}
//		cout << i << " " << s << " " << sumstick << " " << a[l] << " " << l << endl;
 		if (sumstick > 2 * a[l]) {
			ans++;
//			cout << i << endl;
//			cout << s << endl;
		}
	} 
	cout << ans << endl;
	return 0;
}
