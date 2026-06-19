#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	for (int i=1;i<=T;i++) {
		int n;
		cin >> n;
		int A = n%7;
		if (n<7) {
			if (n==1) {
				cout << -1;
			} else if (n==2) {
				cout << 1;
			} else if (n==3) {
				cout << 7;
			} else if (n==4){
				cout << 4;
			} else if (n==5) {
				cout << 2;
			} else if (n==6) {
				cout << 6;
			}
		} else if (n>=8) {
			if (A==1) {
				cout << 10;
				n-=8;
			} else if (A==2) {
				cout << 1;
			} else if (A==3 && n<17) {
				cout << 40;
				n-=4+6;
			} else if (A==3 && n>=17) {
				cout << 200;
				n-=5+6+6;
			} else if (A==4) {
				cout << 20;
				n-=5+6;
			} else if (A==5) {
				cout << 2;
			} else if (A==6) {
				cout << 6;
			}
		} 
		n /= 7;
		for (int i=1;i<=n;i++) {
			cout << 8;
		}
		cout << endl;
	}
	return 0;
}
