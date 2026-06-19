#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5, B = 131;

int n, q;
string s[N][2];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> s[i][0] >> s[i][1];

	while(q--) {
		string a, b; cin >> a >> b;
		
		int l = a.length(), res = 0;
		bool flag = false;
		for(int i = 0; i < l; ++i)
			for(int j = 1; j <= n; ++j) {
				int ll = s[j][0].length();
				if(!flag && ll == l && s[j][0] == a && s[j][1] == b) res++, flag = true;
				else if(a.substr(i, ll) == s[j][0]) {
					// cout << j << "\n" << a.substr(i, ll) << " " << s[j][0] << "\n";
					// cout << a.substr(0, i) << " " << s[j][1] << " " << a.substr(i + ll) << "\n";
					if(a.substr(0, i) + s[j][1] + a.substr(i + ll) == b)
						res++;
				}
			}

		cout << res << "\n";
	}
	return 0;
}
