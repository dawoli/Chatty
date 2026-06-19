#include<bits/stdc++.h>
using namespace std;

int numberList[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int count(int x){
	int ans = 0;
	while(x > 0){
		ans += numberList[x % 10];
		x /= 10;
	}
	return ans;
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t = 0;
	cin >> t;
	for(int ttt = 1; ttt <= t; ttt ++){
		int n;
		cin >> n;
		if(n == 1){
			cout << -1 << endl;
			continue;
		}
		if(n % 7 == 0){
			for(int i = 1; i <= n / 7; i++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n % 7 == 1){
			cout << 1;
			int p = (n - 1) / 7 - 1;
			for(int i = 1; i <= p; i++){
				cout << 8;
			}cout << 9 << endl;
		}else{
			int flag = 0;
			for(int i = 1; i <= 10000000; i++){
				if(count(i) == n){
					cout << i << endl;
					flag = 1;
					break;
				}
			}
			if(!flag) cout << -1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
