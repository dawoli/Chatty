#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int l[10002];
int s[10002][20002];
int r[10002];
int c[10002];
int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 0; ti < T; ti++) {
		int n,k,q;
		scanf("%d%d%d", &n, &k, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &l[i]);
			for (int li = 0; li < l[i]; li++) scanf("%d", &s[i][li]);
			for (int j = 0; j < q; j++) scanf("%d", &r[j], &c[j]);
		}
	}
	return 0; 
}
