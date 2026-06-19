#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

int T, n, a[200005], rb[200005], c[200005], ans;

void dfs(int x) {
	if (x >= n) {
		for (int i = 1; i <= n; i++) {
			bool flag = 0;
			for (int j = i - 1; j >= 1; j--) {
				if (rb[i] == rb[j]) {
					flag = 1;
					if (a[i] == a[j])
						c[i] = a[i];
					else
						c[i] = 0;
					break;
				}
			}
			if (!flag) c[i] = 0;
		}
		int res = 0;
		for (int i = 1; i <= n; i++) 
			res += c[i];
		ans = max(ans, res);
		return ;
	}
	else {
		for (int i = x; i <= n; i++) {
			rb[i] = 1;
			dfs(x + 1);
			rb[i] = 2;
			dfs(x + 1);
			rb[i] = 0;
		}
	}
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(rb, 0, sizeof(rb));
		memset(c, 0, sizeof(c));
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
