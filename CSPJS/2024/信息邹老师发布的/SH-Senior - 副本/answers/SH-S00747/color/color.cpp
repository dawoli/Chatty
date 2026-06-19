#include<bits/stdc++.h> //20·Ö 
using namespace std;
int n, T;
int a[50], b[50];
int main () {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	
	while(T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		long long maxx = 0;
		long long k = 1 << n;
		for(long long i = 0; i < k; i ++) {
			long long score = 0;
			for(int j = 30; j >= 0; j --) {
				b[j+1] = ((i >> j) & 1);
			}
		//	for(int j = 1; j <= n; j ++) {
		//		cout << b[j] << ' ';
		//	}
		//	cout << endl;
			
			for(int j = 1; j <= n; j ++) {
				for(int p = j-1; p >= 0; p --) {
					if(b[p] == b[j]) {
						if(a[p] == a[j]) score += a[j];
						break;
					}
				}
				//cout << score << ' ';
			}
		//	cout << endl;
			maxx = max(maxx, score);
			//cout << score << endl;
		}
		cout << maxx << endl;
	}
	
	return 0;
}

