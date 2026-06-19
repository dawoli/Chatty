#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], cnti;
bool cmp(int x, int y) {return x > y;}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	scanf("%d %d", &n, &m);
	cin >> a[1];
	int searchpoint = a[1];
	for (int i = 2; i <= n * m; i++) cin >> a[i];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cnti++;
			//  none thing !
			if (a[cnti] == searchpoint) {
				if (i % 2 == 1) cout << i << " " << j; //  如果列数为奇数，正常输出
				else {
//					int sumk = (i - 1) * n + 1 + i * n;
//					int reacnt = sumk - cnti; 
					// 实际上是mod之后的结果，应为先输出i，然后输出j
					// 行号i不做变动
					// 特殊判断mod过后为0
					cout << i << " ";
					int mod = cnti % j;
					if (!mod) cout << n;
					else cout << mod;
				} // 否则换行输出 
				exit(0);
			}
		}
	}
	return 0;
}
