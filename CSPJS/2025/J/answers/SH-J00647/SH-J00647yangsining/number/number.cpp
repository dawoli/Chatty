#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s; ll n,a[10];
void input() {
	cin>>s;
}
void solve() {
	n = s.size(); s = '.' + s;
	for(ll i = 1;i <= n;i++) {
		if('0' <= s[i] && s[i] <= '9') a[s[i] - '0'] += 1;
	}
	string ans = "";
	for(ll i = 9;i >= 0;i--) {
		while(a[i]) {
			a[i] -= 1; ans += char(i + '0');
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
} 
