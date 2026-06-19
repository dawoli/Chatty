#include<bits/stdc++.h>
using namespace std;
string s[100];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, cnt = 0;
	cin >> n;
	s[0] = "****";
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	if(n == 1) {
		cout << 51;
		return 0;
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; i++) {
		if(s[i] != s[i - 1]) {
			cnt++;
		}
	}
	cnt = 52 - cnt;
	cout << cnt;
	return 0;
}

