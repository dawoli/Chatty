#include <iostream>
using namespace std; 
int T,n;
int main() {
	freopen("sticks.in",'w',"sticks.in");
	freopen("sticks.out",'r',"sticks.out");
	cin >> T;
	while(T--) {
		cin>>n;
		int k = n % 7;
		if(k == 0) {
			n /= 7;
			for(int i = 0;i < n;i++)
				cout << 8;
		}
		else {
			int len = n / 7 + 1;
			if(len == 1) {
				if(n == 1)
					cout << -1;
				if(n == 2)
					cout << 1;
				if(n == 3)
					cout << 7;
				if(n == 4)
					cout << 4;
				if(n == 5)
					cout << 2;
				if(n == 6)
					cout << 6;
			}
			else if(n % 7 == 1) {
				cout << 1 << 0;
				for(int i = 0;i < len - 2;i++)
					cout << 8;
			}
			else if(n % 7 == 2) {
				cout << 1;
				for(int i = 0;i < len - 1;i++)
					cout << 8;
			}
			else if(n % 7 == 3) {
				cout << 2 << 2;
				for(int i = 0;i < len - 2;i++)
					cout << 8;
			}
			else if(n % 7 == 4) {
				cout << 2 << 0;
				for(int i = 0;i < len - 2;i++)
					cout << 8;
			}
			else if(n % 7 == 5) {
				cout << 2;
				for(int i = 0;i < len - 1;i++)
					cout << 8;
			}
			else {
				cout << 6;
				for(int i = 0;i < len - 1;i++)
					cout << 8;
			}
		}
		cout << endl;
	}
	return 0;
}
