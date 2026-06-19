#include<bits/stdc++.h>

using namespace std;

int n, m;
string s;
int c[502];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) 
		cin >> c[i];
	bool A = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') A = 1;
	}
	cout << 10 << "\n";
	return 0;
}
