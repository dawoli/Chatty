#include<bits/stdc++.h>
using namespace std;
int q[10] = {6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sitcks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n % 7 == 0){
			for (int i = 7; i <= n; i+=7)
				cout << 8;
		}
		else if(n % 7 == 1 && n >= 8){
			cout << 10;
			for (int i = 15; i <= n; i+=7)
				cout << 8;
		}
		else{
			cout << -1;
		}
	}
	return 0;
}
