#include <bits/stdc++.h>
using namespace std;
#define N 60
int n;
string s[N];
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1);
	int m = unique(s + 1, s + n + 1) - s;
	cout << 53 - m << endl;
	return 0;
} 
