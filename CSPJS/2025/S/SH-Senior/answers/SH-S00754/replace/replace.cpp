// CSP RP += 0x3f3f3f3f3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5, L = 5e6;
int n, q, pi[L + 5 << 1];
string s1[N + 5], s2[N + 5];
ll ans;

void cpi(const string &s){
	int n = s.length();
	for(int i = 1; i < n; ++ i){
		pi[i] = pi[i - 1];
		while(pi[i] && s[pi[i]] != s[i]) pi[i] = pi[pi[i] - 1];
		if(s[i] == s[pi[i]]) ++ pi[i];
	}
}

signed main(){
	string t1, t2;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i) cin >> s1[i] >> s2[i];
	while(q --){
		ans = 0;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()){
			cout << "0\n";
			continue;
		}
		for(int t = 1; t <= n; ++ t){
			cpi(s1[t] + '#' + t1);
//			for(int i = 0; i <= s1[t].lengWth() + t1.length(); ++ i) cout << pi[i] << ' ';
//			cout << endl;
			for(int i = s1[t].length() - 1; i < t1.length(); ++ i) if(pi[i + s1[t].length() + 1] == s1[t].length() && t1.substr(0, i - s1[t].length() + 1) + s2[t] + (i < t1.length() - 1 ? t1.substr(i + 1) : string()) == t2) ++ ans;
		}
		cout << ans << '\n';
	}
}

