#include<bits/stdc++.h>
using namespace std;
int n, m, c[600], cnt1, cnt2; string s;
int mod = 998244353;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) {
		cin >> c[i]; if(c[i] == 0) cnt1++;
	}
	for(char c:s) if(c == '0')cnt2++; 
	if(n - m < max(cnt1, cnt2)){
		cout << 0; 
	} else if(m == n) {
		long long ans = 1;
		for(int i = n; i > 0; i--) {
			ans = (ans * i) % mod;
		}
		cout << ans;
	}else cout << 0;
	return 0;
} 
