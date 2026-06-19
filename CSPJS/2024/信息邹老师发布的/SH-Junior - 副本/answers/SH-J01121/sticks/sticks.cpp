#include <bits/stdc++.h>
using namespace std;
int n = 0,T=0,ch=0;
int sn[10] = {6,2,5,5,4,5,6,3,7,6};
int a[7] = {0,16,18,22,20,28,68};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	for(int i = 0;i < T;i++){
		cin >> n;
		//ºÙ÷¶ 
		if(n == 1){
			cout << -1 << endl;
			continue;
		}else if(n <= 7){
			for(int i = 1;i < 9;i++){
				if(sn[i] == n){
					cout << i << endl;
					break;
				}
			}
			continue;
		}
		//’˝Ω‚ 
		int ch = n % 7;
		int ha = (n - ch) / 7 - 1;
		int ya = 0;
		ya = a[ch];
		for(int j = 0;j < ha;j++){
			ya *= 10;
			ya += 8;
		}
		cout << ya << endl;
	}
	return 0;
}
