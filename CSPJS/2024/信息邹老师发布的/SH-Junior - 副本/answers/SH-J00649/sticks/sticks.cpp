#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int sticks[maxn];
int need[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void init(){
	for(int i = 1; i <= maxn; i++){
		int tmp = i;
		while(tmp){
			sticks[i] += need[tmp % 10];
			tmp /= 10;
		}
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	init();
	int T, n;
	cin >> T;
	while(T--){
		bool flag = false;
		cin >> n;
		if(n <= 1){
			cout << -1 << endl;
			continue;
		}
		if(n % 7 == 0){
			int cnt = n / 7;
			for(int i = 1; i <= cnt; i++)
				cout << 8;
			cout << endl;
			continue;
		}
		else if(n % 7 == 1){
			int cnt = n / 7 - 1;
			cout << 10;
			for(int i = 1; i <= cnt; i++)
				cout << 8;
			cout << endl;
			continue;
		}
		for(int i = 1; i <= maxn; i++){
			if(sticks[i] == n){
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << -1 << endl;
	}
	return 0;
}
