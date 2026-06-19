#include<bits/stdc++.h>
using namespace std;
int sticks[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[21] = {0, 0, 1, 7, 4, 2, 6, 8};
int main(){
    freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n < 2){
			cout << -1;
			cout << '\n';
		}else if(n%7==0){
			for(int i=1; i<=n/7; i++){
				cout << 8;
			}
			cout << '\n';
		}else if(n >= 2 && n <= 7){
			cout << ans[n] << '\n';
		}else{
			int p, q = n/7, w = n/7, i = 1;
			while(i <= (w+1)){
				if(i == 1){
					p = 1;
				}else{
					p = 0;
				}
				while(n-sticks[p] > 7*q){
					p++;
				}
				cout << p;
				q--;
				n -= sticks[p];
				i++;
			}
			cout << '\n';
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
