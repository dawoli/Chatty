#include <bits/stdc++.h>
using namespace std;

bool f;
int n, arr[5005], brr;
 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> arr[i];
		if (arr[i] != 1) f = false;
	}
	if (n == 3){
		int m = max(arr[1], arr[2]);
		m = max(arr[2], arr[3]);
		int f = arr[1] + arr[2] + arr[3];
		if (f > 2 * m) cout << 1;
		else cout << 0;
	}
	return 0;
}
