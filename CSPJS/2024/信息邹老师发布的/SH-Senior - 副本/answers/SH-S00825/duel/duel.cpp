#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], flag[N]; 

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	
	// for (int i = 1; i <= n; i++) {
		// printf("%d ", a[i]);
	// }
	// printf("\n");
	
	int sum = n;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (a[i] < a[j] && flag[j] == 0) {
				flag[j] = 1;
				sum--;
				break;
			}
		}
	}
	
	printf("%d", sum);
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
