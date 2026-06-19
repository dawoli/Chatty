#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, special[21] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688};
stack <ll> st;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%lld", &T);
	for (ll i = 1;i <= T;i++){
		scanf("%lld", &n);
		if (n <= 20){
			printf("%lld\n", special[n]);
			continue;
		}else if (n % 7 == 0){
			for (ll qq = 1;qq <= n / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 1){
			printf("10");
			for (ll qq = 1;qq <= (n - 8) / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 2){
			printf("18");
			for (ll qq = 1;qq <= (n - 9) / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 3){
			printf("200");
			for (ll qq = 1;qq <= (n - 17) / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 4){
			printf("20");
			for (ll qq = 1;qq <= (n - 11) / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 5){
			printf("28");
			for (ll qq = 1;qq <= (n - 12) / 7;qq++){
				printf("8");
			}
		}else if (n % 7 == 6){
			printf("68");
			for (ll qq = 1;qq <= (n - 13) / 7;qq++){
				printf("8");
			}
		}
		printf("\n");
	}
	return 0;
}
