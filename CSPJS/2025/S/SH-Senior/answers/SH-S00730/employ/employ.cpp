#include <bits/stdc++.h>
using namespace std;
int n,m,c[510],a[11],ans = 0;
string s;
bool check(string s){
	for (int i = 0;i < s.length();i++){
		if (s[i] == '0') return 0;
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 0;i < n;i++) cin >> c[i];
	if (check(s)){
		int mod = 998244353;
		long long ans = 1,cnt = 0;
		for (int i = 0;i < n;i++) if (c[i] == 0) cnt++;
		for (int i = 1;i <= n - cnt;i++) ans = ans * i % mod;
		cout << ans;
		return 0;
	}
	for (int i = 0;i < n;i++) a[i] = i;
	do{
		int win = 0,lose = 0;
		for (int i = 0;i < s.length();i++){
			if (lose >= c[a[i]]) lose++;
			else if (s[i] == '1') win++;
			else lose++;
		}
		if (win >= m) ans++;
	}while(next_permutation(a,a+n));
	cout << ans;
}
