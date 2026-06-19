#include <cmath>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int t, n, m, k, rest, a[N], b[N], c[N], d[N][20], x[4], s[N][20];
bool fa = true, fb = true;
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++){
		scanf("%d", &c[i]);
		if (int(log2(c[i])) != log2(c[i])){
			fa = false;
		}
	}
	k = int(ceil(log2(n)));
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= (1 << (k - i)); j++){
			scanf("%1d", &d[i][j]);
			if (d[i][j]){
				fb = false;
			}
		}
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d%d", &x[0], &x[1], &x[2], &x[3]);
		for (int i = 1; i <= n; i++){
			b[i] = a[i] ^ x[i % 4];
		}
		long long ans = 0ll;
		if (fa){
			for (int i = 1; i <= m; i++){
				for (int j = 1; (1 << j) <= c[i]; j++){
					for (int l = 1; l <= (1 << (k - j)); l++){
						if (d[j][l] == 0){
							if (b[s[j - 1][l * 2]] >= j){
								s[j][l] = s[j - 1][l * 2];
							}
							else{
								s[j][l] = s[j - 1][l * 2 + 1];
							}
						}
						else{
							if (b[s[j - 1][l * 2 + 1]] >= j){
								s[j][l] = s[j - 1][l * 2 + 1];
							}
							else{
								s[j][l] = s[j - 1][l * 2];
							}
						}
					}
				}
				ans += 1ll * i * s[int(log2(c[i]))][1];
			}
			printf("%lld\n", ans);
		}
		else if (fb){
			for (int i = 1; i <= m; i++){
				for (int j = 1; (1 << j) <= c[i]; j++){
					for (int l = 1; l <= (1 << (k - j)); l++){
						if (b[s[j - 1][l * 2]] >= j){
							s[j][l] = s[j - 1][l * 2];
						}
						else{
							s[j][l] = s[j - 1][l * 2 + 1];
						}
					}
				}
				ans += 1ll * i * s[int(log2(c[i]))][1];
			}
			printf("%lld\n", ans);
		}
	}
}
