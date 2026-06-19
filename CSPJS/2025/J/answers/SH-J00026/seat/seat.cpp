#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 110;
ll n, m, c, r;

struct node{
	ll id, s;
}a[maxn];

bool cmp(node cmp1, node cmp2){return cmp1.s > cmp2.s;}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++){
		cin >> a[i].s;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (ll i = 1; i <= n * m; i++){
		if (a[i].id == 1){
			c = ceil(i * 1.0 / n);
			if (c % 2 == 1){
				r = (i - 1) % n + 1;
			}
			else{
				r = c * n - i + 1;
			}
			cout << c << ' ' << r << endl;
			return 0;
		}
	}
	return 0;
}
