#include <bits/stdc++.h>
using namespace std;
int t,n,stick[20] = {6,2,5,5,4,5,6,3,7,6},gao[15] = {0,0,0,0,0,0,0,00,10,18,23,20,28,68},f;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	cin >> t;
	for(int i = 1;i <= t;i++){
		f = 0;
		cin >> n;
		if(n == 1){
			cout << -1 << endl;
			continue;
		}else if(n == 6){
			cout << 6 << endl;
			continue;
		}
		for(int i = 0;i < 10;i++){
			if(n == stick[i]){
				cout << i << endl;
				f = 1;
				break;
			}
		}
		if(f){
			continue;
		}
		if(n % 7 == 0){
			for(int i = 1;i <= n / 7;i++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n <= 13){
			if(n == 8){
				cout << 10 << endl;
			}else if(n == 9){
				cout << 18 << endl;
			}else if(n == 10){
				cout << 23 << endl;
			}else if(n == 11){
				cout << 20 << endl;
			}else if(n == 12){
				cout << 28 << endl;
			}else if(n == 13){
				cout << 68 << endl; 
			}
		}else{
			cout << gao[n - (n / 7 - 1) * 7];
			for(int i = 1;i <= n / 7 - 1;i++){
				cout << 8;
			}
			cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
