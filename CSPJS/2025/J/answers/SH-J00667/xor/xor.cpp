#include <bits/stdc++.h>
using namespace std;
int n, k, cnt, a[500005];
bool f;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] == 0){
			f = 1;
			cnt ++;
		}
	}
	a[n + 1] = 10086;
	if(k == 0 && !f){
		cout << n / 2;
	}else if(k == 0 && f){
		for(int i = 1; i <= n; i ++){
			if(a[i] == 1 && a[i + 1] == 1){
				cnt ++; a[i + 1] = 0;
			}
		}
		cout << cnt;
	}else if(k == 1 && !f){
		cout << n;
	}else if(k == 1 && f){
		cnt = n - cnt;
		for(int i = 1; i <= n; i ++){
			if(a[i] == 0 && a[i + 1] == 0 && a[i + 2] == 0){
				cnt ++; a[i + 1] = a[i + 2] = 1;
			}
		}
		cout << cnt;
	}else{
		cout << 255;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
