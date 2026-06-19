#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x = 0;
	string s;
	bool flag = false;
	cin >> s;
	for (int i = 9;i >= 0;i--) {
		for (int j = 0;j < s.size();j++) {
			if (s[j] == i + '0') {
				if (s[j] == '0' && flag == false) {
					cout << s[j];
					break;
				}
				flag = true;
				cout << s[j];
			}
		}
	}
	cout << endl;
	return 0;
}
