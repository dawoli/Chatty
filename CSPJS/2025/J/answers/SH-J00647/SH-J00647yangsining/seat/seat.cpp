#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105];
void input() {
	cin>>n>>m;
	for(ll i = 1;i <= n * m;i++) cin>>a[i];
}
void solve() {
	ll id = 0;
	for(ll i = 2;i <= n * m;i++) {
		if(a[1] > a[i]) {
			id = i - 1; break;
		}
	}
	for(ll i = 1;i <= m;i++) {
		if(id > n) id -= n;
		else {
			if(i & 1) {
				cout<<i<<" "<<id<<'\n'; break;
			} else {
				cout<<i<<" "<<n - id + 1<<'\n'; break;
			}
		}
	}
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	solve();
	return 0;
} 
