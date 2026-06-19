#include <bits/stdc++.h>
using namespace std;

int t, n, m, l, v;
int car_d[100010], car_v[100010], car_a[100010];
int de_lct[100010];
int car_exde[100010];
int maxde = 0;
int ans = 0;

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++){
		int ans = 0;
		cin >> n >> m >> l >> v;
		for (int i = 0; i < n; i++){
			scanf("%d %d %d", &car_d[i], &car_v[i], &car_a[i]);
		}
		for (int i = 0; i < m; i++){
			scanf("%d", &de_lct[i]);
			maxde = maxde > de_lct[i] ? maxde : de_lct[i];
		}
		for (int i = 0; i < n; i++){
			if (car_v[i] > v && car_d[i] < maxde){
				ans++;
			}
		}
		cout << ans << ' ' << m-1 << endl;
	}
}
