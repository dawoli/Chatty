#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
const int arr[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
int n[maxn] = {0};
int res[maxn] = {0};
 
int main () {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cin >> n[i];
		if (n == 3) res[i] = 7;
		else if (n == 4) res[i] = 4;
		else if (n == 5) res[i] = 2;
		else if (n == 6) res[i] = 6;
		else if (n == 7) res[i] = 8;
		else {
			
			int num2 = n % 7;
			int num3 = 0;
			for (int num1 = (n + 6) / 7; i >= 1; i--) {
				int x = 0;
				for (int i = num2; i <= 7; i++) {
					if (i == 3) num3 = min(num3 ,7);
					else if (i == 4) num3 = min(num3, 4);
					else if (i == 5) num3 = min(num3, 2);
					else if (i == 6) num3 = min(num3, 6);
					else if (i == 7) num3 = min(num3, 8);
				}
				if (num3 == 7) {
					x = 3;
				} else if (num3 == 4) {
					x = 4; 
				} else if (num3 == 2) {
					x = 5;
				} else if (num3 == 6) {
					x = 6;
				} else if (num3 == 8){
					x= 7;
				}
				res[i] = res[i] * 10 + num3;
				num3 = 0;
				num2 = (n - x) % 7;
			}
		}
	}
	
	for (int i = 1; i <= t; i++) {
		cout << res[i] << endl;
	}
	return 0;
} 
