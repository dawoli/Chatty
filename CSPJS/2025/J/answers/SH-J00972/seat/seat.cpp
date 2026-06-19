#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, cnt = 1, ans1, ans2;
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	x = a[0];
	for(int i = 0;i < n * m;i++){
		if(a[i] > x){
			cnt++;
		}
	}
	ans1 = ceil(1.0 * cnt / n);
	cout << ans1 << " ";
	if(ans1 & 1){
		ans2 = cnt % n;
		if(ans2 == 0){
			ans2 = n;
		}
	}else{
		ans2 = n - (cnt % n) + 1;
		if(ans2 == n + 1){
			ans2 = 1;
		}
	}
	cout << ans2;
	return 0;
}
