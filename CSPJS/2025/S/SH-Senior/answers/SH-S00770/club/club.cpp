#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
	int a1 , a2 , a3;
}a[100001];
int t , n , ans;
void dfs(int x , int f , int s , int t , int sat){
	if (x == n + 1){
		ans = max(ans , sat);
		return;
	}
	if (f < n / 2){
		dfs(x + 1 , f + 1 , s , t , sat + a[x].a1);
	}
	if (s < n / 2){
		dfs(x + 1 , f , s + 1 , t , sat + a[x].a2);
	}
	if (t < n / 2){
		dfs(x + 1 , f , s , t + 1 , sat + a[x].a3);
	}
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &t);
	while (t--){
		ans = 0;
		scanf("%d" , &n);
		for (int i = 1 ; i <= n ; i++){
			scanf("%d%d%d" , &a[i].a1 , &a[i].a2 , &a[i].a3);
		}
		dfs(1 , 0 , 0 , 0 , 0);
		printf("%d\n" , ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
