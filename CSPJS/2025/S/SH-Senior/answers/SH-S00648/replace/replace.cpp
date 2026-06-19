#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n, Q;
string s[N][3], t1, t2;

bool check(int c, int x) {
	int l = s[c][1].size();
	for (int i = 0; i < l; ++ i) 
		if (s[c][1][i] != t1[i + x]) return false;
	return true;
}

int cha(int c, int x) {
	string ss = t1;
	int l = s[c][1].size();
	for (int i = 0; i < l; ++ i) 
		ss[i + x] = s[c][2][i];
//	cout << x << " " << s[c][2] << " " << ss << "\n";
	if (ss == t2) return 1;
	else return 0;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	for (int i = 1; i <= n; ++ i)
		cin >> s[i][1] >> s[i][2];
	
	while (Q --) {
		cin >> t1 >> t2;
		int l = t1.size();
		int ans = 0;
		for (int c = 1; c <= n; ++ c) 
			for (int i = 0; i < l; ++ i) 
				if (check(c, i)) ans += cha(c, i);
		cout << ans << "\n";
	}
	return 0;
}
