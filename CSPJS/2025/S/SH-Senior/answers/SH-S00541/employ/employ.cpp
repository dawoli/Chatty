#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.in" , "w" , stdout);
	int n , m , c , cr[510] ;
	long long ans = 1;
	string s;
	cin >> n >> m >> s;
	for (int i = 0 ; i < n ; i ++){
		cin >> c;
		cr[i] = c;
	}
	for (int i = 1 ; i <= n ; i ++){
		ans *= i;
	}
	ans %= 998244353;
	cout << ans;
	return 0;
	
}
