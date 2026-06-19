#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
struct car {
	int d;
	int v;
	int a;
};
int T = 0;
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--) {
		int n = 0, m = 0, L = 0, V = 0, ans1 = 0, ans2 = 0;
		cin >> n >> m >> L >> V;
		car a[100010] = {};
		vector<int> z(L + 1, 0);
		for(int i = 0; i < n; i++) {
			cin >> a[i].d >> a[i].v >> a[i].a;
		}
		for(int i = 0; i < m; i++) {
			int x = 0;
			cin >> x;
			z[x] = 1;
		} 
		for(int i = 0; i < n; i++) {
			if(a[i].v > V) {
				
				/*if(a < 0) {
					double l = (pow(V, 2) - pow(a[i].v, 2)) * 1.0 / (2 * a[i].a);
					for(int j = a[i].d; j <= a[i].d + l; j++) {
						if(z[j]) {
							ans1++;
							break;
						}
					}
				}*/
				
				if(a[i].a >= 0) {
					for(int j = a[i].d; j <= L; j++) {
						if(z[j]) {
							ans1++;
							break;
						}
					}
				}
								
			}
			/*else if(a > 0) {
				double l = (pow(V, 2) - pow(a[i].v, 2)) * 1.0 / (2 * a[i].a);
				for(int j = a[i].d + l; j <= L; j++) {
					if(z[j]) {
						ans1++;
						break;
					}
				}
			}*/
			
		}
		if(ans1 == 0) {
			cout << ans1 << " " << m << endl;
		}
		else {
			cout << ans1 << " " << m - 1 << endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
