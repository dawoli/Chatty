#include <iostream>
using namespace std;

int a[100005], n;
long long ans;
bool col[100005];
long long cul(){
	int last0 = -1, last1 = -1;
	long long re = 0;
	for (int i = 1; i <= n; i++)
		if (col[i]){
			if (last1 != -1 && a[i] == a[last1])
				re += a[i];
			last1 = i;
		} else {
			if (last0 != -1 && a[i] == a[last0])
				re += a[i];
			last0 = i;
		}
	return re;
}
void dfs(int x){
	if (x > n){
		ans = max(ans, cul());
		return;
	}
	col[x] = 0;
	dfs(x + 1);
	col[x] = 1;
	dfs(x + 1);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ans = 0;
		dfs(1);
		cout << ans << endl; 
	} 
	return 0;
}
