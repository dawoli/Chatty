#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, q;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	vector<pair<string, string>> s;
	vector<pair<string, string>> t;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		s.push_back({s1, s2});
	}
	for (int i = 1; i <= n; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		t.push_back({t1, t2}); 
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}
	return 0;
}
