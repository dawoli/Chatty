#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100010];
int c[100010];
int ans = 0;

void f(int p){
	if (p >= n){
		int _ans = 0;
		for (int i = 0; i < n; i++){
			int va = a[i], co = c[i];
			for (int j = i-1; j >= 0; j--){
				if (c[j] == co && a[j] == va){
					_ans += va;
				}
			}
		}
		ans = ans > _ans ? ans : _ans;
		return;
	}
	c[p] = 1;
	f(p+1);
	c[p] = 0;
	f(p+1);
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++){
		cin >> n;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		ans = 0;
		f(0);
		cout << ans << endl;
	}
}
