#include <bits/stdc++.h>
#define il inline
#define N 200010 
using namespace std;
typedef long long ll;

il ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch != '-' && !(ch >= '0' && ch <= '9')) ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
	return x * f;
}
ll n, Q;
struct node {
	string pre, pins, pint, aft;
} a[N];
map <string, ll> mpa, mpp;
void solveBF() {
	for (int i = 1; i <= n; ++i) {
		string s, t; cin >> s >> t;
		s = " " + s; t = " " + t;
		ll L, R;
//		return;
		for (int j = 1; j < s.size(); ++j)
			if (s[j] != t[j]) {
				L = j; break;
			} 
		for (int j = s.size() - 1; j >= 1; --j)
			if (s[j] != t[j]) {
				R = j; break;
			}
//		cout << L << " " << R << "\n";
		for (int j = 1; j < L; ++j) a[i].pre += s[j];
		for (int j = R + 1; j <= s.size() - 1; ++j) a[i].aft += s[j];
//		return;
		for (int j = L; j <= R; ++j) a[i].pins += s[j];
		for (int j = L; j <= R; ++j) a[i].pint += t[j]; 
//		cout << a[i].pre << " " << a[i].pins << " " << a[i].pint << " " << a[i].aft << "\n"; 
//		return ;
	}
	while(Q--) {
		string s, t;
		cin >> s >> t;
		s = " " + s; t = " " + t;
		ll L, R;
		for (int i = 1; i < s.size(); ++i)
			if (s[i] != t[i]) {
				L = i; break;
			} 
		for (int i = s.size() - 1; i >= 1; --i)
			if (s[i] != t[i]) {
				R = i; break;
			}
		mpp.clear(), mpa.clear();
		string pre, aft, pins, pint;
		for (int i = 1; i < L; ++i) pre += s[i];
		for (int i = R + 1; i <= s.size() - 1; ++i) aft += s[i];
		for (int i = L; i <= R; ++i) pins += s[i];
		for (int i = L; i <= R; ++i) pint += t[i];
		string now = "";
		for (int i = pre.size() - 1; i >= 0; --i)
			mpp[now] = 1, now = pre[i] + now;
		mpp[now] = 1;
		now = "";
		for (int i = 0; i < aft.size(); ++i)
			mpa[now] = 1, now += aft[i]; 
		mpa[now] = 1;
		ll Ans = 0;
		for (int i = 1; i <= n; ++i) {
//			cout << a[i].pre << " " << a[i].aft << " " << a[i].pins << " " << a[i].pint << "\n";
//			cout << mpp[a[i].pre] << " " << mpp.count(a[i].pre) << "\n";
			if ((mpp[a[i].pre] || a[i].pre == "") && (mpa[a[i].aft] || a[i].aft == "")) {
//				cout << "ok " << a[i].pins << " " << a[i].pint << " " << pins << " " << pint << "\n";
				if(a[i].pins == pins && a[i].pint == pint) ++Ans;
			}
				
		}
			
		cout << Ans << "\n";
		
	}
}
int main() {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	n = read(); Q = read();
	if (n <= 100) solveBF();
	return 0;
}

