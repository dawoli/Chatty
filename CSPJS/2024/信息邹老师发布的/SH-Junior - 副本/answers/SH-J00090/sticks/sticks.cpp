#include <bits/stdc++.h>
using namespace std;
int t , n , a , i , j;
string ans , v [10] = {"-1" , "-1" , "1" , "7" , "4" , "2" , "6" , "8"};
int main () {
	freopen ("sticks.in" , "r" , stdin);
	freopen ("sticks.out" , "w" , stdout);
	cin >> t;
	for (a = 1;a <= t;a ++) {
		ans = "";
		cin >> n;
		if (n <= 7) ans += v [n];
		else if (t % 7 == 0) for (i = 0;i < n;i += 7) ans += "8";
		else {
			switch (n % 7) {
				case 1 : {
					if (n == 8) ans += "10";
					else {
						ans += "10";
						for (i = 8;i < n;i += 7) ans += "8";
					}
					break;
				}
				case 2 : {
					if (n == 9) {
						ans += "24";
						break;
					}
					ans += "24";
					for (i = 9;i < n;i += 7) ans += "8";
					break;
				}
				case 3 : {
					if (n == 10) {
						ans += "22";
						break;
					}
					ans += "22";
					for (i = 10;i < n;i += 7) ans += "8";
					break;
				}
				case 4 : {
					if (n == 11) {
						ans += "20";
						break;
					}
					ans += "20";
					for (i = 11;i < n;i += 7) ans += "8";
					break;
				}
				case 5 : {
					if (n == 12) {
						ans += "28";
						break;
					}
					ans += "28";
					for (i = 12;i < n;i += 7) ans += "8";
					break;
				}
				case 6 : {
					if (n == 13) {
						ans += "80";
						break;
					}
					ans += "80";
					for (i = 13;i < n;i += 7) ans += "8";
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
5
1
2
3
6
18
*/
