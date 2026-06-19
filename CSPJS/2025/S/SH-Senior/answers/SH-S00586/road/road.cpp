#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m, k, u[N], v[N], w[N], cc[N], rc[N / 100][N / 100], ans;

int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int j = 0; j < k; j++){
		cin >> cc[j];
		for(int i = 0; i < n; i++){
			cin >> rc[j][i];
		}
	}
	
	sort(w, w + m);
	
	for(int i = 0; i < n - 1; i++){
		ans += w[i];
	}
	
	return 0;
}
