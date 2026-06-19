#include <bits/stdc++.h>
using namespace std;

string s;
int a[100];
int cnt = 1;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0; i <= len; i++) {
		if(s[i] <= '9' && s[i] >= '0') {
			a[cnt] = s[i] - '0';
			cnt++;
		}
	}
	//cout << cnt;
	sort(a + 1, a + cnt, cmp);
	for(int i = 1; i < cnt; i++) {
		cout << a[i];
	}
	return 0;
}
