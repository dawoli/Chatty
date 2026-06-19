#include<bits/stdc++.h>

using namespace std;

int n, maxx, ans, t;
int a[5005];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if(n <= 3){
		if(accumulate(a, a + 3, 0) > 2 * maxx){
			cout << 1 << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	else if(maxx == 1){
		for(int i = 1; i < n; i ++){
			t = 1;
			for(int j = n; j >= i; j --){
				t *= j;
				t = t % 998244353;
			}
			ans += t;
			ans = ans % 998244353;
		}
		cout << ans << endl;
	}
	return 0;
}
