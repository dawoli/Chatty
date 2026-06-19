#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e3 + 5; 
ll n, m, c[MAXN];
char s[100];
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ll p[20];
	iota(p, p + 20, 0);
	cin >> n >> m;
	cin >> s + 1;
	ll ans = 0;
	for(int i = 1; i <= n; i++)cin >> c[i];
	do{
		ll cnt = 0, val = 0;
		for(int i = 1; i <= n; i++){
			// cout << p[i] << ' '<< cnt << ' ' << val << ' ' << s[i];
			if(cnt >= c[p[i]]){
				// cout << "FAIL" << endl;
				cnt++;
				continue;
			}
			// cout << endl;
			if(s[i] == '0')cnt++;
			if(s[i] == '1') val++;
		}
		// cout << val << endl;
		// cout << endl;
		if(val >= m)ans++;
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
	return 0;
}