#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10010;
const int mod = 998244353;
int a[N], p[N], n, ans;
void solve(int b){
	int cnt = 0, maxa = 0;
	for (int i = 1; i <= b; i++){
		cnt += a[p[i]];
		maxa = max(maxa, a[p[i]]);
	}
	if (cnt > maxa * 2){
		ans = (ans + 1) % mod;
	}
	return;
}
void ser (int b, int s, int st){
	for (int i = st; i <= n; i++){
		p[s] = i;
		if (b != s) ser (b, s + 1, i + 1);
		else solve(b); 
	}
	return;
}
signed main(){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n; i++){
		cin >> a[i];
	} 
	for (int i = 3; i <= n; i++){
		ser (i, 1, 1);
	}
	cout << ans; 
	return 0;
} 
