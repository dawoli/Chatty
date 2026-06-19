#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool t1 = true;

string mul2(string s) {
	int l = s.length();
	int a[l+1]; a[0] = 0;
	for (int i = 0; i < l; ++i) {
		int digit = s[i] - '0';
		a[i+1] = digit * 2;
		if (a[i+1] >= 10) {
			a[i+1] -= 10;
			a[i]++;
		}
	}
	
	string ret = "";
	if (a[0] != 0) ret += "1";
	for (int i = 1; i <= l; ++i) {
		ret += (a[i] + '0');
	}
	
	return ret;
}

string power(int exponent) {
	string s = "1";
	for (int i = 1; i <= exponent; ++i) {
		s = mul2(s);
	}
	return s;
}

string minu(string s, int n) {
	int l = s.length();
	int dig = 0;
	int a[l];
	for (int i = 0; i < l; ++i) {
		a[i] = s[i] - '0';
	}
	while (n) {
		int op = n % 10;
		n /= 10;
		dig++;
		a[l-dig] -= op;
	}
	
	for (int i = l-1; i >= 0; --i) {
		if (a[i] < 0) {
			a[i] += 10;
			a[i-1]--;
		}
	}
	
	string ret = "";
	if (a[0] != 0) ret += (a[0] + '0');
	for (int i = 1; i < l; ++i) {
		ret += (a[i] + '0');
	}
	return ret;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] != 1) t1 = false;
	}
	
	if (n <= 2) {
		printf("%d", 0);
		return 0;
	}
	if (n == 3) {
		int mx = max(a[1], max(a[2], a[3]));
		if (a[1] + a[2] + a[3] > 2*mx) printf("%d", 1);
		else printf("%d", 0);
		return 0;
	}
	if (t1) {
		string res = power(n);
		res = minu(res, n+1);
		res = minu(res, (n*(n-1))/2);
		cout << res;
		return 0;
	}
	
	return 0;
}
