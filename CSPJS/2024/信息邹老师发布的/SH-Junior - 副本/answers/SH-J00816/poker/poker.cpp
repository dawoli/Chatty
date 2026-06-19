#include <bits/stdc++.h>
using namespace std;
int n, cnt;
map<string, int> ma;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if(!ma.count(s)) {
			cnt++;
			ma[s]++;
		}
	}
	cout << 52 - cnt;
	return 0;
} 
