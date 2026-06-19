#include <bits/stdc++.h>
using namespace std;
string a[60] = "";
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		a[i] = s;
		bool flag = false;
		for(int j = 1; j<i;j++) {
			if(s == a[j]) {
				flag = !flag;
				break;
			}
		}
		if(!flag)
			cnt++;
	}
	cout << 52 - cnt << endl;
	return 0;
}
