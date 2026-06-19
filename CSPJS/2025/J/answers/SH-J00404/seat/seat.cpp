#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NM = 109;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = l; i <= r; i++)
#define pb push_back
ll n, m;
ll a[NM];
pair<ll, bool> p[NM];
ll x, y;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	re(i, n * m) {
		ll x; cin>>x;
		p[i].first = -x;
		p[i].second = (i == 1); 
	}
	sort(p + 1, p + n * m + 1);
	x = y = 1;
	re(i, n * m) {
		if(p[i].second) {
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		if(x & 1) {
			if(y == n) {
				x++;
			} else {
				y++; 
			}
		} else {
			if(y == 1) {
				x++;
			} else {
				y--;
			}
		}
	}
	return 0;
} 

