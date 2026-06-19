#include<bits/stdc++.h>
using namespace std;
//#define int long long

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt = 0, aim, tmp;
	cin >> aim;
	for(int i = 2;i <= n * m;i++){
		cin >> tmp;
		if(tmp > aim){
			cnt++;
		}
	}
	int r = (cnt / n) + 1;
	int c = (r % 2 == 1 ? (cnt % n) + 1 : n - (cnt % n));
	cout << r << ' ' << c;
	return 0;
}
