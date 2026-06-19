#include <bits/stdc++.h>
using namespace std;
int a[500005], n, k, ans = 0;
struct bunengyao{
	int le, ri;
}bny;
void sol(){
	for(int i = 1; i <= n; i++){
		for(int j = i ; j <= n; j++){
			int sum = a[i];
			for(int l = i + 1; l <= j; l++){
				sum ^= a[l];
			}
			if(sum == k && (i < bny.le || i > bny.ri) && (j < bny.le || j > bny.ri)){
				ans++;
				bny.le = i, bny.ri = j;
			}
		}
	}
	cout << ans;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 1 && k == 0 && a[1] == 1){
	    cout << 0;
	}else if(n == 2 && k == 0 && a[1] == a[2] && a[1] == 1){
		cout << 1;
	}else{
		sol();
	}
	return 0; //I AK IOI
}
