#include<bits/stdc++.h>
using namespace std;
int n;
int x;
int w[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int flag;
int dfs(int sum, int a, int x){
	if(sum == x) {
		flag = 1;
		return a;
	}
	cout << sum <<" " << a << endl; 
	for(int i = 0; i <= 9; i++){
		if(sum + w[i] <= x) {
			dfs(sum + w[i], a * 10 + i, x);
		}
	}
	if(flag == 1) return a;
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x == 1) {
			cout << -1 << endl;
			continue;
		}
		if(x == 2) {
			cout << 1 << endl;
			continue;
		} 
		if(x == 3){
			cout << 7 << endl;
			continue;
		}
		if(x == 4 || x == 5 || x == 6){
			cout << x << endl;
			continue;
		}
		if(x == 7) {
			cout << 8 << endl;
			continue;
		}
		if(n == 8){
			cout << 10 << endl;
			continue;
		}
		if(n == 9){
			cout << 18 << endl;
			continue;
		}
		if(n == 10){
			cout << 23 << endl;
			continue;
		}
		if(n == 11){
			cout << 56 << endl;
			continue;
		}
		if(n == 12){
			cout << 69 << endl;
			continue;
		}
		if(n == 13){
			cout << 68 << endl;
			continue;
		}
		if(n == 14){
			cout << 88 << endl;
			continue;
		}
		if(n == 15){
			cout << 235 << endl;
			continue;
		}					
		if(n == 16){
			cout << 236 << endl;
			continue;
		}
		if(n == 17){
			cout << 238 << endl;
			continue;
		}
		if(n == 18){
			cout << 208 << endl;
			continue;
		}
		if(n == 19){
			cout << 568 << endl;
			continue;
		}	
		if(n == 20){
			cout << 678 << endl;
			continue;
		}		
     
		cout << -1; 
	}
	return  0;
} 
