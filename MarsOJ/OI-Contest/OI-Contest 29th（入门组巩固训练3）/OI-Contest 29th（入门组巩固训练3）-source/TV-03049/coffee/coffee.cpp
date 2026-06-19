#include <iostream>
using namespace std;
int t, n, m, cnt, ans;
string s[10][10];
int main()
{
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		cnt = ans = 0;
		for (int i = 1; i <= 5; i++){
			for (int j = 1; j <= 8; j++){
				cin >> s[i][j];
				if (s[i][j] == "math"){
					cnt++;
				}
			}
		}
		scanf("%d%d", &n, &m);
		n -= 7 - m + 1;
		for (int i = m; i <= 5; i++){
			for (int j = 1; j <= 8; j++){
				if (s[i][j] == "math"){
					ans++;
				}
			}
		}
		ans += n / 7 * cnt;
		n %= 7;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 8; j++){
				if (s[i][j] == "math"){
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

