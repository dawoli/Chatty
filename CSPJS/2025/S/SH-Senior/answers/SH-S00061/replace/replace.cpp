#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, q, ls, lt;
string s, t;
ll cnt = 0;
map<string, string> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> s >> t;
		mp[s] = t;
	}
	while(q--) {
		cnt = 0;
		cin >> s >> t;
		if(mp[s] == t) {
			++cnt;
		}
		ls = s.size(), lt = t.size();
		if(ls != lt) {
			cout << 0 << endl;
			continue;
		}
		for(int l = 1; l <= ls; ++l) {
			for(int i = 1; i + l - 1 <= ls; ++i) {
				string tmp = s.substr(i-1, l);
				if(mp[tmp] != "") {
					string temp = "";
					temp += s.substr(0, i-1);
					temp += mp[tmp];
					temp += s.substr(i+l-1, ls-i-l);
					if(temp == t) ++cnt;
				} 
			} 
		}
		cout << cnt << endl;
	}
	return 0;
}
