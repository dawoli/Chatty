#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
struct node{
	double d, v, a;
}car[N];
int T, check[N], vis[N], vis2[N];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T--){
		int n, m, L, V, ans1 = 0, ans2 = 0;
		cin >> n >> m >> L >> V;
		for (int i = 0; i < n; i++){
			cin >> car[i].d >> car[i].v >> car[i].a;
		}
		for (int i = 0; i < m; i++){
			cin >> check[i];
		}
		for (int i = 0; i < n; i++){
			vis[i] = -1;
		}
		for (int i = 0; i < n; i++){
			vis2[i] = 0;
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (car[j].d <= check[i]){
					if (sqrt(pow(car[j].v, 2) + 2 * car[j].a * (check[i] - car[j].d)) > V && (!vis[j] || i > vis[j])){
						vis[j] = i;
					}
				}
			}
		}
		for (int i = 0; i < n; i++){
			if (vis[i] != -1){
				ans1++;
			}
			if (vis[i] != -1 && !vis2[vis[i]]){
				ans2++;
				vis2[vis[i]] = 1;
			}
		}
		cout << ans1 << " " << m - ans2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
