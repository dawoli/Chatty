#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum, x, ans = 0, t;
	bool f = false;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sum = a[0];
	for(int i = 1;i < n;i++){
		sum ^= a[i];
	}
	for(int i = 0;i < n;i++){
		x = sum;
		f = false;
		t = i;
		for(int j = n - 1;j > i;j--){
			if(x == k){
				f = true;
				cout << a[i] << " " << a[j] << endl;
				t = j - 1;
			}
			x ^= a[j];
		}
		if(f){
			ans++;
		}
		sum ^= a[i];
		i = t;
	}
	cout << ans;
	return 0;
}
