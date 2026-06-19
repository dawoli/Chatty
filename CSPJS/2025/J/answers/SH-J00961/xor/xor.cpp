#include <bits/stdc++.h>
using namespace std;
int n, a[500009], k, cnt, s[500009], e[500009];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 2){
		if((a[1] == k) && (a[2] == k)) cout << 2 << endl;
		else if((a[1] == k) || (a[2] == k) || (a[1] ^ a[2] == k)) cout << 1 <<endl;
		else cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int tmp = a[i];
		if(tmp == k) cnt++;   
		for(int j = i + 1; j <= n; j++){
			tmp = tmp ^ a[j];
			if(tmp == k) cnt++;
		}
	}
	cout << cnt << endl;
	return 0; 
}
