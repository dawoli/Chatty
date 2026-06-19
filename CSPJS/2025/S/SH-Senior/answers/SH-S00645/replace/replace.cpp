#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
pair<string, string> rep[MAXN];
vector<vector<char> > f(128);
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)	cin >> rep[i].first >> rep[i].second;
	while(q--) {
		string x, y;
		int ans = 0;
		cin >> x >> y;
		if(x.length() != y.length()) {
			cout << "0\n";
			continue;
		}
		for(int i = 0; i < n; i++) {
			string tmp = x;
			int a = tmp.find(rep[i].first);
			if(a != -1) {
				int l = rep[i].second.length();
				for(int j = 0; j < rep[i].second.length(); j++) tmp[j + a] = rep[i].second[j];
				if(tmp == y)	ans++;
			}
		}
		cout << ans << "\n";
	}
} 
