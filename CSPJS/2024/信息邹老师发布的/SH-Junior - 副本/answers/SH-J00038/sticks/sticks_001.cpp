#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n == 1){
			cout << -1 << endl;
			continue;
		}else if(n % 7 == 0){
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
			continue;
		}else if(n % 7 == 1){
			cout << 10;
			n -= 8;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
			continue;
		}else if(n % 7 == 2){
			cout << 1;
			n -= 2;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
			continue;
		}else if(n % 7 == 3){
			if(n == 3){
				cout << 7 << endl;
				continue;
			}
			if(n == 10){
				cout << 40 << endl;
				continue;
			}
			cout << 200;
			n -= 17;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
		}else if(n % 7 == 4){
			if(n == 4){
				cout << 4 << endl;
				continue;
			}
			cout << 20;
			n -= 11;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
		}else if(n % 7 == 5){
			cout << 2;
			n -= 5;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
		}else if(n % 7 == 6){
			cout << 6;
			n -= 6;
			n /= 7;
			while(n--) cout << 8;
			cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
