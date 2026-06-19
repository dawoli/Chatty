#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, m, c[510], t;
string s;
bool flaga = true;
long long ans = 1;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		if (c[i] == 0) t++;
	}
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0')
			flaga = false;
	}
	if (flaga){
		for (int i = 1; i <= n; i++){
			ans = ans*i%mod;
		}
		if (n-t < m) cout << 0 << endl;
		else cout << ans << endl;
	}
	return 0;
}
