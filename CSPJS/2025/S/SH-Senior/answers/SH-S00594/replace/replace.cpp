#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][3];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string x, y;
		cin >> x >> y;
		int p1 = 0, p2 = 0, m = x.size();
		for (int j = 0; j < m; j++)
			if (x[j] == y[j]) p1++;
			else break;
		m -= p1;
		x = x.substr(p1, m), y = y.substr(p1, m);
		for (int j = m - 1; j >= p1; j--)
			if (x[j] == y[j]) p2++;
			else break;
		m -= p2;
		x = x.substr(0, m), y = y.substr(0, m);
		s[i][1] = x, s[i][2] = y;
	}
	while (q--){
		string t1, t2;
		cin >> t1 >> t2;
		int p1 = 0, p2 = 0, m = t1.size();
		for (int i = 0; i < m; i++)
			if (t1[i] == t2[i]) p1++;
			else break;
		m -= p1;
		t1 = t1.substr(p1, m), t2 = t2.substr(p1, m);
		for (int i = m - 1; i ; i--)
			if (t1[i] == t2[i]) p2++;
			else break;
		m -= p2;
		t1 = t1.substr(0, m), t2 = t2.substr(0, m);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (t1 == s[i][1] && t2 == s[i][2])
				ans++;
		cout << ans << endl;
	}
	return 0;
} 
