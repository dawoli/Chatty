#include<bits/stdc++.h>
using namespace std;
long long n, a[100010], ans;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	ans = n;
	sort(a + 1, a + n + 1);
	for(int i = n, j = n - 1; i >= 1 && j >= 1; i--){
		while(j >= 1 && a[j] == a[i]){
			j--;
		}
		if(j == 0){
			break;
		} 
		ans--;
		j--;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
