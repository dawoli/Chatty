#include<bits/stdc++.h>
using namespace std;

int cnt(int n){
	int cnt = 0;
	int size = 0;
	while(n != 0){
		size++;
		int tmp = n % 10;
		n /= 10;
		if(tmp == 0){
			cnt += 6;
		}else if(tmp == 1){
			cnt += 2;
		}else if(tmp == 2){
			cnt += 5;
		}else if(tmp == 3){
			cnt += 5;
		}else if(tmp == 4){
			cnt += 4;
		}else if(tmp == 5){
			cnt += 5;
		}else if(tmp == 6){
			cnt += 6;
		}else if(tmp == 7){
			cnt += 3;
		}else if(tmp == 8){
			cnt += 8;
		}else if(tmp == 9){
			cnt += 7;
		}
		return cnt;
	}
}
int low(int n){
	int k = n / 8;
	int ans = 8;
	for(int i = 1; i < k; i++){
		ans *= 10;
		ans += 8;
	}
}
int up(int n){
	int k = n / 2;
	int ans = 2;
	for(int i = 1; i < k; i++){
		ans *= 10;
		ans += 1;
	}
}
void solve(){
	int n;
	cin >> n;
	if(n % 7 == 0){
		
		for(int i = 0; i < n / 7; i++){
			cout << 9;
		}
		cout << endl;
		return ;
	}
	if(n == 1){
		cout << -1 << endl;
		return;
	}
	for(int i = 1; i < 10000000000; i++){
		if(cnt(i) == n){
			cout << i << endl;
			return ;
		}
	}
	cout << -1 << endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
