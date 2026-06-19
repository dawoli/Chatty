#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, m, cnt, p[505], ans, cntzero;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		if(p[i] == 0) cnt++;
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') cntzero++;
	}
	//m == n
	if(cnt == 0 && cntzero == 0){
		ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * i % mod;
	}
	cout << ans;
	return 0;
}
