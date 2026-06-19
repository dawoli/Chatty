#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int T, n;
int nL[MAXN];

string convertD2B(long long n, int l) {
	string ans = "";
	while (n != 0) {
		if (n % 2 == 1) ans += "1";
		else ans += "0";
		n /= 2;
	}
	int tmp = l - ans.length();
	for (int i = 0; i < tmp; i++) ans += "0";
	return ans;
}

int solve(string opt) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (opt[j] != opt[i]) continue;
			else {
				if (nL[i] == nL[j]) c += nL[i];
				break;
			}
		}
	}
	return c;
}

long long mi(int n) {
	long long ans = 1;
	for (int i = 0; i < n; i++) ans *= 2;
	return ans;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> nL[i];
		int maxc = 0;
		for (long long i = 0; i < mi(n); i++) {
			int c = solve(convertD2B(i, n));
			if (c > maxc) maxc = c;
		}
		cout << maxc << endl;
	}
	return 0;
}
