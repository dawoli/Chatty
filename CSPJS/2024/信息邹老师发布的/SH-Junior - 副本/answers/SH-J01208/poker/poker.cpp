#include <bits/stdc++.h>
using namespace std;
int n, ans;
map<string, int> a;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (!a[s]) ans++;
		a[s]++;
	}
	cout << 52 - ans << endl;
	return 0;
} 
//MAN!
//What can I say?
//Mamba out!
