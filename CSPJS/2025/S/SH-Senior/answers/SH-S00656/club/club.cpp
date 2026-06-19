#include<bits/stdc++.h>
using namespace std;

int t, n, ans;
bool ta, tb;
struct node{
	int a, b, c;
}a[100005];

void dfs(int step, int sum, int x, int y, int z){
	if (step > n){
		ans = max(ans, sum);
		return;
	}
	if (x+1 <= n/2) dfs(step+1, sum+a[step].a, x+1, y, z);
	if (y+1 <= n/2) dfs(step+1, sum+a[step].b, x, y+1, z);
	if (z+1 <= n/2) dfs(step+1, sum+a[step].c, x, y, z+1);
}

bool cmpa(node x, node y){
	return x.a > y.a;
}

bool cmpb(node x, node y){
	return abs(x.a - x.b) > abs(y.a - y.b);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ta = tb = true;
		for (int i = 1; i <= n; i ++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].c != 0) tb = false;
			if (a[i].b != 0 || a[i].c != 0) ta = false;
		}
		ans = 0;
		if (n <= 10){
			dfs(1, 0, 0, 0, 0);
			cout << ans << endl;
		} else if(ta){
			sort(a+1, a+n+1, cmpa);
			for (int i = 1; i <= n/2; i ++){
				ans += a[i].a;
			}
			cout << ans << endl;
		} else if (tb){
			int x = 0, y = 0;
			sort(a+1, a+n+1, cmpb);
			for (int i = 1; i <= n; i ++){
				if (a[i].a > a[i].b && x < n/2){
					ans += a[i].a;
					x ++;
				}else if (y < n/2){
					ans += a[i].b;
					y ++;
				}else{
					ans += a[i].a;
					x ++;
				}
			}
			cout << ans << endl;
		}
		
	}
	return 0;
} 
