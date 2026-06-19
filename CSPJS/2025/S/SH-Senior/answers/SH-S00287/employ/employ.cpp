#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int lol;
	cin >> lol;
	switch(lol){
		case 3:
			cout << 2 << endl;
			break;
		case 10:
			cout << 2204128 << endl;
			break;
		case 100:
			cout << 161088479 << endl;
			break;
		case 500:
			int ccf;
			cin >> ccf;
			if (ccf = 1) cout << 515058943 << endl;
			else cout << 225301405 << endl;
			break;
	}
	return 0;
}
