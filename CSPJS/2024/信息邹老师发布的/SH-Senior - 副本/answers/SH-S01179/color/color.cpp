#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[1919810], ans;
string bin(int x){
	string res;
	while(x){
		char c = '0' + (x % 2);
		res = c + res;
		x /= 2;
	}
	while(res.length() < n){
		res = '0' + res;
	}
	return res;
}
int qpow(int x, int y){
	if(y == 0){
		return 1;
	} else if(y == 1){
		return x;
	} else{
		int tmp = qpow(x, y / 2);
		if(y & 1){
			return tmp * tmp * x;
		} else{
			return tmp * tmp;
		}
	}
}
signed main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%lld", &t);
	while(t--){
		ans = -1;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		for(int i = 0; i < qpow(2, n); i++){
			string s = " " + bin(i);
			int tmp = 0;
			for(int j = 1; j <= n; j++){
				for(int k = j - 1; k; k--){
					if(s[j] == s[k] && a[j] == a[k]){
						tmp += a[j];
					}
				}
			}
			ans = max(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
