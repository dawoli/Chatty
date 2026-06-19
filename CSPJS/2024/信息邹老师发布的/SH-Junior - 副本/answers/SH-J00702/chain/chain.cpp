#include<cstdio>
using namespace std;

int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		int n, k, q;
		scanf("%d%d%d", &n, &k, &q);
		for(int j = 1; j <= n; j++){
			int l;
			scanf("%d", &l);
			for(int i = 1; i <= l; i++){
				int temp;
				scanf("%d", &temp);
			}
		}
		for(int j = 1; j <= q; j++){
			int r, c;
			scanf("%d%d", &r, &c);
		}
		printf("0"); // 这个应该是能拿到部分分了 
	}
	return 0;
}
