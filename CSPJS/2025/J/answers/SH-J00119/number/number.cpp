#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int cnt = 0;
	cin >> s;
	for (char c : s) {
		if (c >= '0' && c <= '9')
			a[cnt++] = c - '0';
	}
	sort(a, a + cnt, cmp);
	for (int i = 0; i < cnt; i++) cout << a[i];
	return 0;
} 
