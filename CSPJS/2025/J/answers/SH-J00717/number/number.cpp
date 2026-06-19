#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size(),a[100001];
	for (int i = 0;i < n;i++) if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') cout << s[i]; return 0;
	for (int i = 0;i < n;i++) if (n == 1 && (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')) cout << s[i] << endl; return 0;
	for (int i = 0;i < n;i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			a[i] = s[i];
		}
		sort(a[i] + a,a[i] + a + 1);
	}
	for (int i = 0;i < n;i++) {
		cout << a[i];
	}
	return 0;
}
