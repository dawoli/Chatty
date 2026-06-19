#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 

struct car {
	int d, v, a;
} cars[N];

int testers[N];

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		
		int count1 = 0;
		int minus = 0;
		for (int i = 0; i < n; i++) {
			cin >> cars[i].d >> cars[i].v >> cars[i].a;
		}
		
		for (int i = 0; i < m; i++) {
			cin >> testers[i];
		}
		
		for (int i = 0; i < n; i++) {
			int d0 = cars[i].d;
			int v0 = cars[i].v;
			int a0 = cars[i].a;
			
			int test0 = -1;
			for (int j = 0; j < m; j++){
				if (testers[j] >= d0) {
					test0 = j;
					break;
				}
			}
			
			/*if (a0 > 0) {
				float r = (V * V - v0 * v0) / (2 * a0);
				if (r + d0 > V) {
					continue;
				}
				for (int j = test0; j < m; j++) {
					if (testers[j] > r) {
						count++;
						break;
					}
				}
			}*/
			
			if (a0 == 0){
				if (v0 <= V) {
					continue;
				}
				else {
					if (test0 == -1) {//测速全部在路口前 
						continue;
					}
					count1++;
				}
			}
			
			/*else if (a0 < 0){
				if (v0 < V) {
					continue;
				}
				else {
					float r = (v0 * v0) / (2 * (-a0));
					for (int j = test0; j < m; j++) {
						if (testers[j] > r) {
							count++;
							break;
						}
					}
				}
			}*/
		}
		minus = m-1;
		
		cout << count1 << ' ' << minus << endl;
	}
	
	return 0;
}
