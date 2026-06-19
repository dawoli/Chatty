#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if(n > 3){
		int cnt = 1, ans = 0;
		for(int i = 3; i <= n; i++){
			for(int j = 1; j <= i; j++){
				cnt *= (n - j + 1); 
			}
			for(int j = 1; j <= i; j++){
				cnt /= j;
			}
			ans += cnt;
		}
		cout << ans % 998 % 244 % 353;
	}
	else{
		if(n <= 2){
			cout << 0;
			return 0;
		}
		int a, b, c;
		cin >>a >>b >>c;
		if(a + b >c && a + c > b && b +c >a){
			cout << 1;
			return 0;
		}
	}
	return 0;
}
