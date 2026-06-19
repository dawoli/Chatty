#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lgn = 1e5+10;
deque <int> a[lgn];
ll b[lgn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	int uu, vv;
	for (int i = 1; i <= m; i++){
		cin >> uu >> vv;
		a[uu].push_back(vv);
		a[vv].push_back(uu);
	}
	return 0;
}
