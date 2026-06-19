#include<bits/stdc++.h>
using namespace std;
int n, m, a = 0, b, w = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> b;
			if(a == 0) a = b;
			else if(b > a) w++;
		}
	}
	int ni, mi;
	mi = ceil(w * 1.0 / n);
	int s = w % n ? w % n : n;
	if(mi % 2) ni = s;
	else ni = m - s + 1;
	cout << mi << " " << ni;
	return 0;
}
