#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		int n, a[100005][3], maxans = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 3; j++) cin >> a[i][j];
		}for(long long i = 0; i < (int)pow(3, n); i++) {
			int bin[100005] = {0}, cnt = 0, state[3] = {0}, s = 0;
			for(long long j = i; j > 0; j /= 3) {
				bin[cnt++] = j % 3;
				state[j % 3]++;
			}if(state[0] > n / 2 || state[1] > n / 2 || state[2] > n / 2) {
				continue;
			}else{
				for(int j = 0; j < cnt; j++) s += a[j][bin[j]];
				maxans = max(maxans, s);
			}
		}cout << maxans << endl;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
