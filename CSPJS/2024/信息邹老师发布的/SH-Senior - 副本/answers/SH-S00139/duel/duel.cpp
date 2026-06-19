#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, ans, cost, r[N], cnt[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &r[i]);
		cnt[r[i]]++;
	}
	for (int i = 1; i <= 100000; i++){
		int fight = n - cost - cnt[i];
		if (fight >= cnt[i]){
			cost += cnt[i];
			ans += cnt[i];
		}
		else{
			ans += fight;
			break;
		}
	}
	printf("%d\n", n - ans);
}
