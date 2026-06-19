#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n, r[N], cnt[N], rem;
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> r[i];
	for(int i = 1; i <= n; i++) cnt[r[i]]++;
	sort(r + 1, r + n + 1);
	for(int i = 1; i <= 100000; i++)
		if(cnt[i] > 0 && rem > 0) {
			rem = max(0, rem - cnt[i]);
			rem += cnt[i];
		}else rem += cnt[i];
	cout << rem << endl;
	return 0;
} 
