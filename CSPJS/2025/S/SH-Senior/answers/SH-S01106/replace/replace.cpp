#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200007, L = 2000007, BS = 97, MOD = 998244853;

int md(int _) {
	return (_ % MOD + MOD) % MOD;
}

int n, q;
string s1[N], s2[N];
int hs1[N], hs2[N];
int tmp[L];

int qpow(int n, int m) {
	if(m == 0) return 1;
	int tmp = qpow(n, m/2);
	if(m & 1) return tmp * tmp % MOD * n % MOD;
	else return tmp * tmp % MOD;
}

int get_hs(string s, int* tmp) {
	for(unsigned int i=0; i<s.length(); i++) 
		tmp[i+1] = (tmp[i] * BS % MOD + (s[i] - 'a')) % MOD;
	return tmp[s.length()];
}

string t1, t2;
int hst1[L], hst2[L];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin >> s1[i] >> s2[i];
		hs1[i] = get_hs(s1[i], tmp);
		hs2[i] = get_hs(s2[i], tmp); 
	}
	while(q--) {
		cin >> t1 >> t2;
		get_hs(t1, hst1); get_hs(t2, hst2);
		int lt = t1.length();
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			int ls = s1[i].length();
			if(ls > lt) continue;
//			cout << s1[i] << ' ' << s2[i] << endl;
			for(int _=1; _+ls-1<=lt; _++) 
				if( md(hst1[_+ls-1] - hst1[_-1] * qpow(BS, ls)) == hs1[i]
				and md(hst2[_+ls-1] - hst2[_-1] * qpow(BS, ls)) == hs2[i] 
				and md(hst1[_-1]) == md(hst2[_-1])
				and md(hst1[lt] - hst1[_+ls-1] * qpow(BS, lt-ls-_+1)) == md(hst2[lt] - hst2[_+ls-1] * qpow(BS, lt-ls-_+1))) {
//					cout << _ << ' ' << _+ls-1 << " WITH: " << s1[i] << ' ' << s2[i] << endl; 
					cnt++;
				}
		}
		cout << cnt << endl;
	}
	return 0;
}




 
