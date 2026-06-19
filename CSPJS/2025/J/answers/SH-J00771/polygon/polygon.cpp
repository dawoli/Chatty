#include<algorithm>
#include<cstdio>
using namespace std;
int n , a[5001] , maxx;
long long ans;
void dfs(int s , int maxx , int sum){
	if (s == n + 1){
		if (sum > 2 * maxx){
			ans++;
			if (ans >= 998244353){
				ans -= 998244353;
			}
		}
		return;
	}
	dfs(s + 1 , maxx , sum); 
	dfs(s + 1 , max(maxx , a[s]) , sum + a[s]);
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	scanf("%d" , &n);
	for (int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
		maxx = max(maxx , a[i]);
	} 
	sort(a + 1 , a + n + 1);
	if (maxx > 1){
		dfs(1 , 0 , 0);
		printf("%lld" , ans);
	}else{
		putchar('0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
