#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 510;
int c[maxn],id[maxn];
int n,m;
string s;
void solve1() {
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		id[i] = i; //the ist day employ id[i]
	}
	int ans = 0;
	do {
		int sum = 0,cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(s[i] == '1' && cnt < c[id[i]]) {
				sum++;
			}
			else cnt++;
		}
		if(sum >= m) {
			ans++;
		}
	} while(next_permutation(id + 1,id + n + 1));
	cout << ans << "\n";
}
void solve2() {
	int a1 = 0,a2;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if(c[i] == 0) a1++;
	}
	a2 = n - a1;
	if(a2 < m) {
		cout << 0 << "\n";
	}
	else {
		int ans = 1;
		for (int i = 0; i < m; i++) {
			ans = (ans * (a2 - i)) % mod; 
		}
		for (int i = n - m; i >= 1; i--) {
			ans = (ans * i) % mod;
		}
		cout << ans << "\n";
	}
}
void solve3() {
	cout << 0 << "\n";
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if(n <= 10) {
		solve1();
		return 0;
	}
	cin >> s;
	s = ' ' + s;
	bool flag = 1; 
	for (int i = 1; i <= n; i++) {
		if(s[i] == '0') {
			flag = 0;
			break;
		}
	}
	if(flag == 1) {
		solve2();
		return 0;
	}
	if(n == m) {
		solve3();
		return 0;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

11 9
11111111111
0 9 9 9 9 9 9 9 9 9 9
*/
