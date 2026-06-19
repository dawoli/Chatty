#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int cnt[N], pn[N], a[N];
// bool coln[N];

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= N; i++) {
			cnt[i] = 0;
			pn[i] = 0;
			a[i] = 0;
		}
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			// cout << a[i] << " ";
			cnt[a[i]]++;
		}
		
		
		int cnt1 = 0, id1 = 1;
		for (int i = 1; i <= N; i++) {
			if (cnt[i] >= 2) {
				cnt1++;
				pn[id1] = i;
				id1++;
			}
		}
		if (cnt1 == 0) {
			printf("0\n");
			continue;
		}
		
		int sum = 0;
		sort(pn + 1, pn + id1);
		for (int i = id1 - 1; i >= 1; i--) {
			int cnt2 = cnt[pn[i]] / 2;
			sum += cnt2 * pn[i];
		}
		printf("%d\n", sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
