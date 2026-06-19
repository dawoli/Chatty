#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 1;i <= n;i++){
		ans *= n;
		ans %= mod;
	}
	cout << ans;
}
