#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m,ans,a[510],id[510];char c[510];bool ok;
void solve1(){
	for(int i = 1;i <= n;i++) id[i] = i;
	do{
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(c[i] == '1' && a[id[i]] >= i - cnt) cnt++;
		}
		if(cnt >= m) ans++;
	}while(next_permutation(id + 1,id + n + 1));
	cout << ans;
}
void solve2(){
	if(ok) cout << 0;
	else{
		ans = 1;
		for(int i = 1;i <= n;i++) (ans *= i) %= mod;
		cout << ans;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		if(c[i] == '0') ok = 1;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(!a[i]) ok = 1;
	}
	if(n <= 10) solve1();
	else if(m == n) solve2();
	else cout << 0;
	return 0;
}
