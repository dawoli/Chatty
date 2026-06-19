#include <bits/stdc++.h>
using namespace std;

string s;

int ans[1005];

bool check(char c) {
	int a = c - '0';
	if (a >= 0 && a <= 10) {
		return true;
	}
	else {
		return false;
	}
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cur = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (check(s[i])) {
			cur++;
			ans[cur] = s[i] - '0';
		}
	}
	sort(ans+1,ans+cur+1,cmp);
	string last;
	for (int i = 1; i <= cur; i++) {
		last += (char)(ans[i] + '0');
	}
	cout << last << endl;
	return 0;
}
