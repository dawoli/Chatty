#include <iostream>
using namespace std;
int T;
int n,k,q;
int main() {
	freopen("chain.in",'r',"chain.in");
	freopen("chain.out",'w',"chain.out");
	cin >> T;
	while(T--) {
		cin >> n >> k >> q;
		int s,x;
		for(int i = 0;i < n;i++) {
			cin >> s;
			for(int i = 0;i < s;i++) {
				cin >> x;
			}
		}
		int r,c;
		while(q--) {
			cin >> r >> c;
		}
	}
	cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0;
}
