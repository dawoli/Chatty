#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int u, v, w;
long long sum;
int c;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		sum += w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c;
	}
	cout << sum << endl;
	return 0;
}
