#include <cstdio>
#include <bits/stdc++.h> 
using namespace std;

int List[5005];

int n;

long long ans = 0;

int run(long long Max, long long Sum, long long Num, int Check){
	if(Check > n){
		ans += (Sum > 2 * Max && Num >= 3);
		if(ans >= 998244353){
			ans %= 998244353;
		}
		return 0;
	}
	run(Max, Sum, Num, Check + 1);
	run(max(Max, 1ll * List[Check]), Sum + List[Check], Num + 1, Check + 1);
	return 0;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &List[i]);
	}
	if(n >= 500){
		long long add = 1;
		for(int i = 0; i < n; i++){
			add = add * (n - i) / (i + 1);
			if(i >= 2){
				ans += add % 998244353;
			}
		}
		printf("%lld", ans);
	}
	run(0, 0, 0, 1);
	printf("%lld", ans);
	return 0;
}
