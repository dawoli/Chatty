#include <bits/stdc++.h>
using namespace std;

vector<int> v;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	//100
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
	return 0;
}
