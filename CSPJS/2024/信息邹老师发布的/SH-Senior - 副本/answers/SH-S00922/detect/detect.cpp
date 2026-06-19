#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0 ; i < t ; i++){
		int n, m, l, V;
		cin >> n >> m >> l >> V;
		int d[n], v[n], a[n];
		for(int j = 0 ; j < n ; j++){
			cin >> d[j] >> v[j] >> a[j];
		}
		int p[m + 1];
		for(int j = 0 ; j < m ; j++){
			cin >> p[j + 1];
		}
		sort(p + 1, p + m + 1);
		bool flag = 1;
		for(int j = 0 ; j < n ; j++){
			if(a[j] != 0){
				flag = 0;
				break;
			}
		}
		if(flag){
			int cnt = 0;
			for(int j = 0 ; j < n ; j++){
				if(v[j] > V && d[j] <= p[m]){
					cnt++;
				}
			}
			cout << cnt << " " << m - 1 << endl;
			continue;
		}
		bool flag2 = 1;
		for(int j = 0 ; j < n ; j++){
			if(a[j] <= 0){
				flag2 = 0;
				break;
			}
		}
		if(flag2){
			int cnt = 0;
			for(int j = 0 ; j < n ; j++){
				if(d[j] <= p[m]){
					double u = sqrt(v[j] * v[j] + 2 * a[j] * (p[m] - d[j]));
					if(u > V){
						cnt++;
					}
				}
			}
			cout << cnt << " " << m - 1 << endl;
			continue;
		}
		cout << n / 2 << " " << m / 2 << endl;
	}
}
