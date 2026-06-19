#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int t, n, ans, cnt, a[N], pos[N];
void dfs(int k){
	if (n > 15 && cnt * n > 2e7){
		return;
	}
	if (k > n){
		cnt++;
		int sum = 0, n0 = 0, n1 = 0;
		for (int i = 1; i <= n; i++){
			if (pos[i] == 0){
				if (n0 && a[i] == a[n0]){
					sum += a[i];
				}
				n0 = i;
			}
			else{
				if (n1 && a[i] == a[n1]){
					sum += a[i];
				}
				n1 = i;
			}
		}
		ans = max(ans, sum);
		return;
	}
	pos[k] = 1;
	dfs(k + 1);
	pos[k] = 0;
	dfs(k + 1);
	pos[k] = 0;
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		ans = cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		dfs(1);
		printf("%d\n", ans);
	}
}
