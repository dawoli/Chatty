#include <bits/stdc++.h>
using namespace std;
int T, n;
const int N = 100010;
int a[N], b[N], c[N], ans, anss[N];
int main(){
	freopen ("color.in", "r", stdin);
	freopen ("color.out", "w", stdout);
	cin >> T;
	for (int k = 1; k <= T; k++){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		} 
		while (b[0] != 1){
			memset(c, 0, sizeof(c));
			ans = 0;
			for (int i = 1; i <= n; i++){
				for (int j = i - 1; j >= 1; j--){
					if (b[j] == b[i]){
						if (a[i] == a[j]){
							c[i] = a[i];
							break;
						}
					}
				}
			}
			b[n] += 1;
			for (int j = n; j >= 1; j--){
				if (b[j] == 2){
					b[j] = 0;
					b[j - 1]++;
				}
			}
			int sum = 0;
			for (int i = 1; i <= n; i++){
				//cout << c[i] << " ";
				sum += c[i];
			}
			//cout << endl;
			//cout << sum << endl;
			ans = max(ans, sum);
		}
		anss[k] = ans;
	}
	for (int i = 1; i <= T; i++){
		cout << anss[i] << endl;
	}
	return 0;
}
