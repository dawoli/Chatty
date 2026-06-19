#include<bits/stdc++.h>
using namespace std;
int n, m, c[20009], a[20009];
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> c[i];
	for(int i = 1; i <= n; i++){
		cout << log(n) / log(2) + 1 << endl;
	}
	return 0;
}

