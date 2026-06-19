#include <bits/stdc++.h>
using namespace std;
int n, a[5005], countx;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(long long i = 7; i < (int)pow(2, n); i++) {
		int bin[5005], cnt = 0, maxn = 0;
		long long s = 0;
		for(int j = i; j > 0; j /= 2) {
			bin[cnt] = j % 2;
			if(j % 2 == 1) maxn = cnt, s += a[cnt];
			cnt++;
		}if(a[maxn] < s - a[maxn]) countx++;
	}cout << countx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
