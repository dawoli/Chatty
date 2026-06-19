#include<algorithm>
#include<cstdio>
using namespace std;
int n , m , c[501] , ans;
char s[501];
bool a[501];
void dfs(int x , int res , int f){
	if (x == n + 1){
		if (res >= m){
			ans++;
			if (ans >= 998244353){
				ans -= 998244353;
			}
		}
		return;
	}
	for (int i = 1 ; i <= n ; i++){
		if (!a[i]){
			a[i] = 1;
			if (f < c[i] && s[x] - 48){
				dfs(x + 1 , res + 1 , f);
			}else{
				dfs(x + 1 , res , f + 1);
			}
			a[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	scanf("%d%d%s" , &n , &m , s + 1);
	for (int i = 1 ; i <= n ; i++){
		scanf("%d" , &c[i]);
	}
	dfs(1 , 0 , 0);
	printf("%d" , ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
