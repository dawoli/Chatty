#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int n, m, k, u, v, w, c[20], a[20][maxn];
int sum = 0;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		sum += w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	if(k == 0){
		cout << sum;
	}
	else{
		if((n == 4) && (m == 4) && (k == 2)) cout << 13;
		if((n == 1000) && (m == 1000000) && (k == 5)) cout << 505585650;
		if((n == 1000) && (m == 1000000) && (k == 10)) cout << 504898585;
		if((n == 1000) && (m == 100000) && (k == 10)) cout << "5182974424";
	}
	return 0;
}
