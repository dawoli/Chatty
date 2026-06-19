#include<bits/stdc++.h>
using namespace std;

int n, m, a[107], b;

bool cmp(int x, int y){ return x > y; }

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i = -~i) cin >> a[i];
	b = a[0];
	sort(a, a + n * m, cmp);
	for(int i = 0; i < n * m; i = -~i){
		if(a[i] == b){
			cout << -~(i / n) << ' ';
			if((i / n + 1) % 2) cout << -~(i % n);
			else cout << n - i % n;
			break;
		}
	}
	return 0;
}
