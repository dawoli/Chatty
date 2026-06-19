#include <iostream>
using namespace std;

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		if (n == 1){
			cout << -1 << endl;
			continue;
		}
		int modi = n % 7;
		switch (modi){
			case 0:{
				for (int i = 1; i <= n / 7; i++)
					cout << 8;
				cout << '\n';
				break;
			}
			case 1:{
				cout << "10";
				for (int i = 1; i <= n / 7 - 1; i++)
					cout << 8;
				cout << '\n';
				break;
			}
			case 2:{
				cout << 1;
				for (int i = 1; i <= n / 7; i++)
					cout << 8;
				cout << '\n';
				break;
			}
			case 3:{
				if (n / 7 == 0) cout << "7\n";
				else if (n / 7 == 1) cout << "22\n";
				else{
					cout << "200";
					for (int i = 1; i <= n / 7 - 2; i++)
						cout << 8;
					cout << '\n';
				}
				break;
			}
			case 4:{
				if (n / 7 == 0) cout << "4\n";
				else{
					cout << "20";
					for (int i = 1; i <= n / 7 - 1; i++)
						cout << 8;
					cout << '\n';
				}
				break;
			}
			case 5:{
				cout << 2;
				for (int i = 1; i <= n / 7; i++)
					cout << 8;
				cout << '\n';
				break;
			}
			case 6:{
				cout << 6;
				for (int i = 1; i <= n / 7; i++)
					cout << 8;
				cout << '\n';
				break;
			}
		}
	} 
	return 0;
}
