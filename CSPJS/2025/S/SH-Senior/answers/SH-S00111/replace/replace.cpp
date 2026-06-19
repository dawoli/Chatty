#include <bits/stdc++.h>
using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
}

const int MXL = 2.5e6 + 5;
unordered_map<string, string> rep;
int sz, same_begin, same_end;
string from, to, r1, r2;

long long count(int begin) {
	r1.clear();
	r2.clear();
	r1.reserve(sz-begin);
	r2.reserve(sz-begin);
	long long ans = 0;
	for (int i = begin; i < sz; i++) {
		r1.push_back(from[i]);
		r2.push_back(to[i]);
		auto it = rep.find(r1);
		if (it != rep.end() && it -> second == r2) {
			if (begin <= same_begin+1 && i >= same_end-1) {
//				cout << begin << " ~ " << i << ": " << r1 << endl;
				ans++;
			}
		}
	}
	return ans;
}

int main() {
    init();

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	string s1, s2;
    	cin >> s1 >> s2;
    	rep.insert({s1, s2});
	}
	
	for (int i = 0; i < q; i++) {
		cin >> from >> to;
		sz = from.size();
		
		same_begin = sz-1;
		same_end = 0;
		for (int i = 0; i < sz; i++) {
			if (from[i] != to[i]) {
				same_begin = i-1;
				break;
			}
		}
		for (int i = sz-1; i >= 0; i--) {
			if (from[i] != to[i]) {
				same_end = i+1;
				break;
			}
		}
		
		long long ans = 0;
		for (int i = 0; i < sz; i++) {
			ans += count(i);
		}
		cout << ans << endl;
	}
}
