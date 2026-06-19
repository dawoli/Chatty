#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	queue<int> num;
	for (int i=0; i<s.size(); i++) {
		if (s[i]>='0' && s[i]<='9') {
			num.push(s[i]-'0');
		}
	}
	int a[num.size()] = {0};
	int sizen = num.size();
	for (int i=0; i<sizen; i++) {
		a[i] = num.front();
		num.pop();
	}
	sort(a, a+sizen, cmp);
	for (int i=0; i<sizen; i++) {
		cout << a[i];
	}
	cout << endl;
	return 0;
}
